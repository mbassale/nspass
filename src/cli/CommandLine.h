//
// Created by Marco Bassaletti on 16-03-21.
//

#ifndef OWNPASS_COMMANDLINE_H
#define OWNPASS_COMMANDLINE_H

#include <string>
#include <vector>
#include <boost/program_options.hpp>
#include "./input/SecretInput.h"
#include "../commands/Command.h"

namespace OwnPass::CLI {
	class CommandLine {
	public:
		CommandLine(int argc, char** argv, OwnPass::CLI::Input::SecretInput& secret_input);
		int run();
	private:
		int argc;
		char** argv;
		OwnPass::CLI::Input::SecretInput& secret_input;

		void initialize_master_password(const std::vector<OwnPass::Commands::CommandPtr>& commands);
	};
}

#endif //OWNPASS_COMMANDLINE_H
