//
// Created by Marco Bassaletti on 16-03-21.
//

#ifndef OWNPASS_COMMANDLINE_H
#define OWNPASS_COMMANDLINE_H

#include "../OwnPass.h"
#include <boost/program_options.hpp>
#include "./input/SecretInput.h"
#include "./input/ConfirmInput.h"
#include "../commands/Command.h"

namespace OwnPass::CLI {
	class CommandLine {
	public:
		CommandLine(int argc, char** argv, Input::SecretInput& secret_input, Input::ConfirmInput& confirm_input);
		int run();
	private:
		static constexpr auto DefaultStorageLocation = "ownpass.db";
		int argc;
		char** argv;
		Input::SecretInput& secret_input;
		Input::ConfirmInput& confirm_input;

		void initialize_master_password(const std::vector<OwnPass::Commands::CommandPtr>& commands);
		bool confirm(const std::vector<OwnPass::Commands::CommandPtr>& commands);
	};
}

#endif //OWNPASS_COMMANDLINE_H
