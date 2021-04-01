//
// Created by Marco Bassaletti on 31-03-21.
//
#include "../../OwnPass.h"
#include "../../commands/HelpCommand.h"
#include "../../commands/CopyPasswordCommand.h"
#include "../InvalidCommandSyntaxException.h"
#include "CopyPasswordCommandParser.h"

namespace OwnPass::CLI::Parsers {
	using namespace std;
	using OwnPass::Commands::CommandPtr;
	using OwnPass::Commands::HelpCommand;
	using OwnPass::Commands::CopyPasswordCommand;
	using OwnPass::CLI::InvalidCommandSyntaxException;
	namespace po = boost::program_options;

	CommandPtr CopyPasswordCommandParser::operator()()
	{
		po::options_description opt_desc{ "Copy command options" };
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
			return CommandPtr{ new HelpCommand{ app, opt_desc }};
		}

		if (vm.count("username") == 0) {
			throw InvalidCommandSyntaxException(format_error("Missing required username.", opt_desc));
		}

		auto category = vm["category"].as<string>();
		auto site = vm.count("site") ? vm["site"].as<string>() : "";
		auto application = vm.count("application") ? vm["application"].as<string>() : "";
		auto username = vm["username"].as<string>();
		auto group = site.empty() ? application : site;

		return CommandPtr{ new CopyPasswordCommand{ app, category, group, username }};
	}
}
