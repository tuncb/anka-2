use std::fs;

use clap::Parser;

mod engine;
mod instructions;
mod lexer;
mod stack;

use crate::engine::run;

#[derive(Parser, Debug)]
#[command(version, about, long_about = None)]
struct Args {
    #[arg(short, long)]
    filename: String,
}

fn main() {
    let args = Args::parse();

    let filename = args.filename;
    // Load the input from the file and store it in a variable
    let contents = match fs::read_to_string(&filename) {
        Ok(contents) => contents,
        Err(error) => {
            eprintln!("Error loading file {}: {}", filename, error);
            std::process::exit(1);
        }
    };

    println!("code: {}", contents);

    let tokens = lexer::lex(&contents);
    println!("---tokens---");
    for token in &tokens {
        println!("{}: {}", token.token_type.to_string(), token.value);
    }

    let tape = instructions::fill_tape(&tokens);
    println!("---tape---");
    for item in &tape.items {
        match item {
            instructions::TapeItemType::Instruction(instruction) => {
                println!("{}", instruction.to_string());
            }
            instructions::TapeItemType::IntegerConstant(value) => {
                println!("{}", value);
            }
        }
    }

    run(&tape);
}
