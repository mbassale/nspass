use std::env;
use std::process;

use nspass;

fn main() {
    let args: Vec<String> = env::args().collect();
    let command_line_args = nspass::CommandLineArgs::new(&args).unwrap_or_else(|err| {
        eprintln!("Problem parsing arguments: {}", err);
        process::exit(1);
    });
    if let Err(err) = nspass::run(&command_line_args) {
        eprintln!("Error running nspass: {}", err);
        process::exit(1);
    }
}
