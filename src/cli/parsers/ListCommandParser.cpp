//
// Created by Marco Bassaletti on 27-03-21.
//

#include "../../OwnPass.h"
#include "../../commands/HelpCommand.h"
#include "../../commands/ListCategoriesCommand.h"
#include "../../commands/ListGroupsCommand.h"
#include "../../commands/ListPasswordsCommand.h"
#include "../InvalidCommandSyntaxException.h"
#include "ListCommandParser.h"

namespace OwnPass::CLI::Parsers {
	using namespace std;
	using OwnPass::Commands::CommandPtr;
	using OwnPass::Commands::HelpCommand;
	using OwnPass::Commands::ListCategoriesCommand;
	using OwnPass::Commands::ListGroupsCommand;
	using OwnPass::Commands::ListPasswordsCommand;
	using OwnPass::CLI::InvalidCommandSyntaxException;
	namespace po = boost::program_options;

	CommandPtr ListCommandParser::operator()()
	{
		po::options_description list_desc{ "List command options" };
		list_desc.add_options()
				("help,h", "This help")
				("categories,c", "List categories")
				("sites,s", "List sites")
				("applications,a", "List applications")
				("passwords,p", "List passwords")
				("format,f", po::value<string>(), "Format: stdout (default) or csv");

		try {
			vector<string> opts = po::collect_unrecognized(parsed.options, po::include_positional);
			po::store(po::command_line_parser(opts).options(list_desc).run(), vm);
			po::notify(vm);
		}
		catch (po::error& err) {
			throw InvalidCommandSyntaxException(format_error(err.what(), list_desc));
		}

		if (vm.empty() || vm.count("help")) {
			return CommandPtr{ new HelpCommand{ app, list_desc }};
		}

		if (vm.count("format")) {

		}

		if (vm.count("categories")) {
			return CommandPtr{ new ListCategoriesCommand{ app }};
		}
		else if (vm.count("sites")) {
			return CommandPtr{ new ListGroupsCommand{ app, GroupType::Site }};
		}
		else if (vm.count("applications")) {
			return CommandPtr{ new ListGroupsCommand{ app, GroupType::Application }};
		}
		else if (vm.count("passwords")) {
			return CommandPtr{ new ListPasswordsCommand{ app }};
		}
		else {
			throw InvalidCommandSyntaxException(format_error("Missing argument.", list_desc));
		}
	}
}
