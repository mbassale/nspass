//
// Created by Marco Bassaletti on 16-03-21.
//

#ifndef OWNPASS_COMMANDLINE_H
#define OWNPASS_COMMANDLINE_H

#include "../NSPass.h"
#include <boost/program_options.hpp>
#include "./input/SecretInput.h"
#include "./input/ConfirmInput.h"
#include "../commands/Command.h"

namespace NSPass::CLI {
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

		void initialize_master_password(const std::vector<NSPass::Commands::CommandPtr>& commands);
		bool confirm(const std::vector<NSPass::Commands::CommandPtr>& commands);
	};
}

#endif //OWNPASS_COMMANDLINE_H
