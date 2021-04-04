//
// Created by Marco Bassaletti on 18-03-21.
//

#ifndef OWNPASS_COMMANDPARSER_H
#define OWNPASS_COMMANDPARSER_H

#include "../NSPass.h"
#include <boost/program_options.hpp>
#include "../commands/Command.h"

namespace NSPass::CLI {

	typedef std::function<Commands::CommandPtr()> CommandCreatorCallback;

	struct CommandTable {
		std::string name;
		CommandCreatorCallback command_creator;
		CommandTable(std::string_view name, CommandCreatorCallback command_creator)
				:name{ name }, command_creator{ std::move(command_creator) } { }
	};

	class CommandParser {
	public:
		CommandParser(NSPass::Application& app, int argc, char** argv);

		[[nodiscard]] const std::vector<Commands::CommandPtr>& get_commands() const { return commands; }

	private:
		static constexpr auto ProgramCaption = R"(NSPass v0.1 - © 2021, Marco Bassaletti <bassaletti@gmail.com>.
Simple commands-line password management program.
Allowed Options)";
		NSPass::Application& app;
		int argc;
		char** argv;
		boost::program_options::options_description opt_descriptions{ ProgramCaption };
		boost::program_options::positional_options_description positional_opt_descriptions;
		boost::program_options::variables_map vm;
		std::vector<Commands::CommandPtr> commands;

		void create_options();
		void parse_options();
		bool is_help_command(Commands::Command& command);
	};
}

#endif //OWNPASS_COMMANDPARSER_H
