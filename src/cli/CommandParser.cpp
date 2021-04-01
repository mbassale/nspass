//
// Created by Marco Bassaletti on 18-03-21.
//

#include "../OwnPass.h"
#include <boost/program_options.hpp>
#include "../Application.h"
#include "../commands/Command.h"
#include "../commands/HelpCommand.h"
#include "../commands/VerboseCommand.h"
#include "../commands/VersionCommand.h"
#include "../commands/SetStorageLocationCommand.h"
#include "./parsers/InspectStorageCommandParser.h"
#include "./parsers/CreatePasswordCommandParser.h"
#include "./parsers/CopyPasswordCommandParser.h"
#include "./parsers/PurgeStorageCommandParser.h"
#include "./parsers/DumpStorageCommandParser.h"
#include "./parsers/ListCommandParser.h"
#include "./parsers/ImportCommandParser.h"
#include "CommandParser.h"

using namespace std;
namespace po = boost::program_options;
using namespace OwnPass::Commands;
using namespace OwnPass::CLI::Parsers;

namespace OwnPass::CLI {

	CommandParser::CommandParser(OwnPass::Application& app, int argc, char** argv)
			:app{ app }, argc{ argc }, argv{ argv }
	{
		create_options();
		parse_options();
	}

	void CommandParser::create_options()
	{
		static constexpr auto CommandHelp = R"(command to execute.
Command can be one of:
    create: Creates a password.
)";
		opt_descriptions.add_options()
				("help,h", "show this help.")
				("verbose,v", "enable verbose output.")
				("version", "show program version.")
				("storage", po::value<string>(), "overrides default storage location (ownpass.db)")
				("command", po::value<string>(), CommandHelp)
				("args", po::value<vector<string>>(), "command arguments.");

		positional_opt_descriptions.add("command", 1).add("args", -1);
	}

	void CommandParser::parse_options()
	{
		po::parsed_options parsed = po::command_line_parser(argc, argv).options(opt_descriptions)
				.positional(positional_opt_descriptions).allow_unregistered().run();
		po::store(parsed, vm);
		po::notify(vm);

		if (vm.count("verbose")) {
			commands.emplace_back(new VerboseCommand{ app });
		}
		if (vm.count("version")) {
			commands.emplace_back(new VersionCommand{ app });
		}
		if (vm.count("storage")) {
			commands.emplace_back(new SetStorageLocationCommand{ app, vm["storage"].as<string>() });
		}

		bool has_help_command = false;
		if (vm.count("command")) {
			string command_name = vm["command"].as<string>();

			CommandTable command_table[] = {
					CommandTable{ "create", CreatePasswordCommandParser{ app, parsed, vm }},
					CommandTable{ "copy", CopyPasswordCommandParser{ app, parsed, vm }},
					CommandTable{ "inspect", InspectStorageCommandParser{ app, parsed, vm }},
					CommandTable{ "purge", PurgeStorageCommandParser{ app, parsed, vm }},
					CommandTable{ "dump", DumpStorageCommandParser{ app, parsed, vm }},
					CommandTable{ "list", ListCommandParser{ app, parsed, vm }},
					CommandTable{ "import", ImportCommandParser{ app, parsed, vm }},
			};

			for (auto& command_row : command_table) {
				if (command_row.name == command_name) {
					auto command_ptr = command_row.command_creator();
					if (is_help_command(*command_ptr))
						has_help_command = true;
					commands.push_back(command_ptr);
				}
			}
		}
		if (!has_help_command && (vm.empty() || vm.count("help"))) {
			commands.emplace_back(new HelpCommand{ app, opt_descriptions });
		}
	}

	bool CommandParser::is_help_command(Command& command)
	{
		return command.get_name() == HelpCommand::Name;
	}
}
