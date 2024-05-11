use std::os::raw::c_void;

pub struct Stack {
    pub i32_data: Vec<i32>,
    pub pointer_data: Vec<*mut c_void>,
}

impl Stack {
    pub fn new() -> Self {
        Stack {
            i32_data: Vec::new(),
            pointer_data: Vec::new(),
        }
    }
}
