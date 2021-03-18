//
// Created by Marco Bassaletti on 18-03-21.
//

#ifndef OWNPASS_COMMANDPARSER_H
#define OWNPASS_COMMANDPARSER_H

#include <memory>
#include <string>
#include <vector>
#include <boost/program_options.hpp>
#include "../commands/Command.h"

namespace OwnPass::CLI {
	class CommandParser {
	public:
		CommandParser(OwnPass::Application& app, int argc, char** argv);

		[[nodiscard]] const std::vector<std::shared_ptr<OwnPass::Commands::Command>>& get_commands() const { return commands; }

	private:
		static constexpr auto ProgramCaption = R"(OwnPass v0.1 - © 2021, Marco Bassaletti <bassaletti@gmail.com>.
Simple commands-line password management program.
Allowed Options)";
		OwnPass::Application& app;
		int argc;
		char** argv;
		boost::program_options::options_description opt_descriptions{ ProgramCaption };
		boost::program_options::positional_options_description positional_opt_descriptions;
		boost::program_options::variables_map vm;
		std::vector<std::shared_ptr<OwnPass::Commands::Command>> commands;

		void create_options();
		void parse_options();
		void create_commands();
	};
}

#endif //OWNPASS_COMMANDPARSER_H
