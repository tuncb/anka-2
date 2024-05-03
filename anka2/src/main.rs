use std::fs;

use clap::Parser;

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
    println!("{}", contents);
}