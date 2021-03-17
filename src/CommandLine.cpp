//
// Created by Marco Bassaletti on 16-03-21.
//

#include <vector>
#include <iostream>
#include <boost/program_options.hpp>
#include "Application.h"
#include "CommandLine.h"

using OwnPass::Application;
namespace po = boost::program_options;
using namespace std;

namespace OwnPass {

	CommandLine::CommandLine(int argc, char** argv)
			:argc{ argc }, argv{ argv }
	{
	}

	int CommandLine::run()
	{
		create_options();
		parse_options();
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

		// global clean-up
		app.cleanup();

		return 0;
	}
}
