use std::error::Error;

pub struct CommandLineArgs<'a> {
    args: &'a [String],
}

impl<'a> CommandLineArgs<'a> {
    pub fn new(args: &[String]) -> Result<CommandLineArgs, &str> {
        Ok(CommandLineArgs { args: args })
    }
}

pub fn run(command_line_args: &CommandLineArgs) -> Result<(), Box<dyn Error>> {
    Ok(())
}
