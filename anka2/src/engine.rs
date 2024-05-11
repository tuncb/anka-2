use std::alloc::{alloc, dealloc, Layout};
use std::os::raw::c_void;

use crate::{
    instructions::{Instruction, Tape, TapeItemType},
    stack::Stack,
};

fn allocate(stack: &mut Stack) {
    let array_size = stack.i32_data.pop().unwrap() as usize;
    let count_size = std::mem::size_of::<usize>();
    let size = array_size + count_size;

    let layout = Layout::from_size_align(size, std::mem::align_of::<u8>()).unwrap();
    let raw_memory = unsafe { alloc(layout) as *mut c_void };

    unsafe {
        *(raw_memory as *mut usize) = size;
        let array_start = raw_memory.offset(std::mem::size_of::<usize>() as isize);
        stack.pointer_data.push(array_start);
    }
}

fn deallocate(stack: &mut Stack) {
    let array_start = stack.pointer_data.pop().unwrap();
    unsafe {
        let pointer_start = array_start.offset(-(std::mem::size_of::<usize>() as isize));
        let size = *(pointer_start as *const usize);
        dealloc(
            pointer_start as *mut u8,
            Layout::from_size_align(size, std::mem::align_of::<u8>()).unwrap(),
        );
    }
}

pub fn run(tape: &Tape) {
    let mut stack = Stack::new();

    for item in tape.items.iter().rev() {
        match item {
            TapeItemType::Instruction(instruction) => match instruction {
                Instruction::Allocate => {
                    allocate(&mut stack);
                }
                Instruction::Deallocate => {
                    deallocate(&mut stack);
                }
            },
            TapeItemType::IntegerConstant(value) => {
                stack.i32_data.push(*value);
            }
        }
    }
}
