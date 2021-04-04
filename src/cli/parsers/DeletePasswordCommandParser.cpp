//
// Created by Marco Bassaletti on 04-04-21.
//

#include "../../OwnPass.h"
#include "../../commands/HelpCommand.h"
#include "../../commands/DeletePasswordCommand.h"
#include "../InvalidCommandSyntaxException.h"
#include "DeletePasswordCommandParser.h"

namespace OwnPass::CLI::Parsers {
	using OwnPass::Commands::CommandPtr;

	using namespace std;
	using OwnPass::Commands::CommandPtr;
	using OwnPass::Commands::HelpCommand;
	using OwnPass::Commands::DeletePasswordCommand;
	using OwnPass::CLI::InvalidCommandSyntaxException;
	namespace po = boost::program_options;

	CommandPtr DeletePasswordCommandParser::operator()()
	{
		po::options_description opt_desc{ "Import command options" };
		opt_desc.add_options()
				("help,h", "This help")
				("category,c", po::value<string>(), "Password Category")
				("application,a", po::value<string>(), "Application name")
				("site,s", po::value<string>(), "Site name")
				("username,u", po::value<string>(), "Username");

		try {
			vector<string> opts = po::collect_unrecognized(parsed.options, po::include_positional);
			po::store(po::command_line_parser(opts).options(opt_desc).run(), vm);
			po::notify(vm);
		}
		catch (po::error& err) {
			throw InvalidCommandSyntaxException(format_error(err.what(), opt_desc));
		}

		if (vm.empty() || vm.count("help")) {
			return std::make_shared<HelpCommand>(app, opt_desc);
		}

		if (vm.count("username") == 0) {
			throw InvalidCommandSyntaxException(format_error("Missing required username.", opt_desc));
		}

		DeletePasswordCommand::Filter filter;
		filter.category_search = vm.count("category") ? vm["category"].as<string>() : "";
		filter.site_search = vm.count("site") ? vm["site"].as<string>() : "";
		filter.application_search = vm.count("application") ? vm["application"].as<string>() : "";
		filter.username_search = vm["username"].as<string>();

		return CommandPtr{ new DeletePasswordCommand{ app, filter }};
	}
}
