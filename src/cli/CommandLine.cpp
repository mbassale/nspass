//
// Created by Marco Bassaletti on 16-03-21.
//

#include <boost/log/trivial.hpp>
#include "../Application.h"
#include "CommandParser.h"
#include "../commands/CommandRunner.h"
#include "CommandLine.h"

using OwnPass::Application;
using OwnPass::Commands::CommandRunner;
using namespace std;

namespace OwnPass::CLI {

	CommandLine::CommandLine(int argc, char** argv, Input::SecretInput& secret_input,
			Input::ConfirmInput& confirm_input)
			:argc{ argc }, argv{ argv }, secret_input{ secret_input }, confirm_input{ confirm_input }
	{
	}

	int CommandLine::run()
	{
		auto& app = Application::instance();

		// global initialization
		app.init();
		app.get_vault().set_storage_location(DefaultStorageLocation);

		auto call_cleanup = [&app] { app.cleanup(); };

		try {
			CommandParser command_parser{ app, argc, argv };
			auto& commands = command_parser.get_commands();
			initialize_master_password(commands);
			if (confirm(commands)) {
				CommandRunner command_runner{ commands };
				command_runner.run();
			}
		}
		catch (std::runtime_error& err) {
			BOOST_LOG_TRIVIAL(fatal) << "Runtime Error: " << err.what() << std::endl;
			call_cleanup();
			return 1;
		}
		catch (std::exception& ex) {
			BOOST_LOG_TRIVIAL(fatal) << "Error: " << ex.what() << std::endl;
			call_cleanup();
			return 1;
		}

		// global clean-up
		call_cleanup();
		return 0;
	}

	void CommandLine::initialize_master_password(const std::vector<Commands::CommandPtr>& commands)
	{
		for (auto& command_ptr : commands) {
			if (command_ptr->requires_master_password()) {
				auto master_password = secret_input.request();
				auto& app = Application::instance();
				app.get_vault().set_master_password(master_password);
				return;
			}
		}
	}

	bool CommandLine::confirm(const vector<OwnPass::Commands::CommandPtr>& commands)
	{
		for (auto& command_ptr : commands) {
			if (command_ptr->requires_confirmation()) {
				return confirm_input.request();
			}
		}
		return true;
	}
}
