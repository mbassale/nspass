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

	CommandLine::CommandLine(int argc, char** argv)
			:argc{ argc }, argv{ argv }
	{
	}

	int CommandLine::run()
	{
		auto& app = Application::instance();

		// global initialization
		app.init();

		auto call_cleanup = [&app] { app.cleanup(); };

		try {
			CommandParser command_parser{ app, argc, argv };
			auto& commands = command_parser.get_commands();
			CommandRunner command_runner{ commands };
			command_runner.run();
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
}
