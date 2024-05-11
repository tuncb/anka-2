use strum_macros::Display;

use crate::lexer::{Token, TokenType};

#[derive(Display)]
pub enum Instruction {
    Allocate,
    Deallocate,
}

pub enum TapeItemType {
    Instruction(Instruction),
    IntegerConstant(i32),
}

pub struct Tape {
    pub items: Vec<TapeItemType>,
}

impl Tape {
    pub fn new() -> Self {
        Tape { items: Vec::new() }
    }
}

pub fn fill_tape(tokens: &Vec<Token>) -> Tape {
    let mut tape = Tape::new();

    for token in tokens {
        match token.token_type {
            TokenType::Word => match token.value {
                "allocate" => tape
                    .items
                    .push(TapeItemType::Instruction(Instruction::Allocate)),
                "deallocate" => tape
                    .items
                    .push(TapeItemType::Instruction(Instruction::Deallocate)),
                _ => panic!("Unknown instruction: {}", token.value),
            },
            TokenType::Number => tape
                .items
                .push(TapeItemType::IntegerConstant(token.value.parse().unwrap())),

            _ => panic!("Unexpected token: {:?}", token.token_type),
        }
    }

    return tape;
}
