//
// Created by Marco Bassaletti on 16-03-21.
//

#ifndef OWNPASS_COMMANDLINE_H
#define OWNPASS_COMMANDLINE_H

#include <string>
#include <vector>
#include <boost/program_options.hpp>

namespace OwnPass {
	class CommandLine {
	public:
		CommandLine(int argc, char** argv);
		int run();

		[[nodiscard]] const boost::program_options::variables_map& get_variables_map() const { return vm; }
		[[nodiscard]] const std::vector<std::string_view>& get_executed_commands() const { return executed_commands; }
		
	private:
		static constexpr auto ProgramCaption = R"(OwnPass v0.1 - © 2021, Marco Bassaletti <bassaletti@gmail.com>.
Simple commands-line password management program.
Allowed Options)";

		int argc;
		char** argv;
		std::string show_password;
		boost::program_options::options_description opt_descriptions{ ProgramCaption };
		boost::program_options::variables_map vm;
		std::vector<std::string_view> executed_commands;

		void create_options();
		void parse_options();
		bool should_show_help();
		int run_commands();
	};
}

#endif //OWNPASS_COMMANDLINE_H
