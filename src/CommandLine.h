//
// Created by Marco Bassaletti on 16-03-21.
//

#ifndef OWNPASS_COMMANDLINE_H
#define OWNPASS_COMMANDLINE_H

#include <string>
#include <boost/program_options.hpp>

namespace OwnPass {
	class CommandLine {
	public:
		CommandLine(int argc, char** argv);
		int run();
	private:
		static constexpr auto ProgramCaption = R"(OwnPass v0.1 - © 2021, Marco Bassaletti <bassaletti@gmail.com>.
Simple command-line password management program.
Allowed Options)";

		int argc;
		char** argv;
		std::string show_password;
		boost::program_options::options_description opt_descriptions{ ProgramCaption };
		boost::program_options::variables_map vm;
		void create_options();
		void parse_options();
		bool should_show_help();
		int run_commands();
	};
}

#endif //OWNPASS_COMMANDLINE_H
