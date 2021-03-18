//
// Created by Marco Bassaletti on 18-03-21.
//

#include <vector>
#include <boost/program_options.hpp>
#include "../Application.h"
#include "../commands/Command.h"
#include "../commands/HelpCommand.h"
#include "../commands/VerboseCommand.h"
#include "../commands/VersionCommand.h"
#include "CommandParser.h"

using namespace std;
namespace po = boost::program_options;
using namespace OwnPass::Commands;

namespace OwnPass::CLI {

	CommandParser::CommandParser(OwnPass::Application& app, int argc, char** argv)
			:app{ app }, argc{ argc }, argv{ argv }
	{
		create_options();
		parse_options();
		create_commands();
	}

	void CommandParser::create_options()
	{
		opt_descriptions.add_options()
				("help,h", "show this help")
				("verbose,v", "enable verbose output")
				("version", "show program version")
				("command", po::value<string>(), "command to execute")
				("args", po::value<vector<string>>(), "command arguments");

		positional_opt_descriptions.add("command", 1).add("args", -1);
	}

	void CommandParser::parse_options()
	{
		po::parsed_options parsed = po::command_line_parser(argc, argv).options(opt_descriptions)
				.positional(positional_opt_descriptions).allow_unregistered().run();
		po::store(parsed, vm);
		po::notify(vm);

		if (vm.count("command")) {
			string command_name = vm["command"].as<string>();
		}
	}

	void CommandParser::create_commands()
	{
		if (vm.empty() || vm.count("help")) {
			commands.emplace_back(new HelpCommand{ app, opt_descriptions });
		}
		if (vm.count("verbose")) {
			commands.emplace_back(new VerboseCommand{ app });
		}
		if (vm.count("version")) {
			commands.emplace_back(new VersionCommand{ app });
		}
	}
}
