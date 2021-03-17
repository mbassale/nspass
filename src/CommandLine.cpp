//
// Created by Marco Bassaletti on 16-03-21.
//

#include <vector>
#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/program_options.hpp>
#include "Application.h"
#include "CommandLine.h"
#include "./commands/CommandRunner.h"

using OwnPass::Application;
using OwnPass::Commands::CommandRunner;
namespace po = boost::program_options;
using namespace std;

namespace OwnPass {

	CommandLine::CommandLine(int argc, char** argv)
			:argc{ argc }, argv{ argv }
	{
		create_options();
		parse_options();
	}

	int CommandLine::run()
	{
		if (should_show_help()) {
			std::cout << opt_descriptions << std::endl;
			return 1;
		}
		return run_commands();
	}

	void CommandLine::create_options()
	{
		opt_descriptions.add_options()
				("help,h", "show this help")
				("verbose,v", "enable verbose output")
				("version", "show program version")
				("search,f", boost::program_options::value<vector<string>>(), "search for passwords")
				("show,s", boost::program_options::value<string>(&show_password), "show password");
	}

	void CommandLine::parse_options()
	{
		po::store(po::parse_command_line(argc, argv, opt_descriptions), vm);
		po::notify(vm);
	}

	bool CommandLine::should_show_help()
	{
		return (vm.empty() || vm.count("help"));
	}

	int CommandLine::run_commands()
	{
		auto& app = Application::instance();

		if (vm.count("verbose")) {
			app.config(Application::LogMode::VERBOSE);
		}
		else {
			app.config(Application::LogMode::NORMAL);
		}

		// global initialization
		app.init();

		auto call_cleanup = [&app]{ app.cleanup(); };

		try {
			CommandRunner command_runner{ app, vm };
			command_runner.run();
			executed_commands = command_runner.get_executed_commands();
		} catch (std::runtime_error &err) {
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
