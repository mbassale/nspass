//
// Created by Marco Bassaletti on 18-03-21.
//

#include <iostream>
#include <string>
#include <sstream>
#include "../../commands/CreatePasswordCommand.h"
#include "../InvalidCommandSyntaxException.h"
#include "CreatePasswordCommandParser.h"
#include "Parser.h"

namespace OwnPass::CLI::Parsers {
	using namespace std;
	using OwnPass::Commands::CommandPtr;
	using OwnPass::Commands::CreatePasswordCommand;
	using OwnPass::CLI::InvalidCommandSyntaxException;
	namespace po = boost::program_options;

	CommandPtr OwnPass::CLI::Parsers::CreatePasswordCommandParser::operator()()
	{
		po::options_description create_desc{ "Create command options" };
		create_desc.add_options()
				("category", po::value<string>()->default_value("Default"), "Password Category")
				("application", po::value<string>(), "Application name")
				("site", po::value<string>(), "Site name")
				("url", po::value<string>()->default_value(""), "Site url")
				("description", po::value<string>()->default_value(""), "Description")
				("username", po::value<string>()->required(), "Username")
				("password", po::value<string>()->required(), "Password");

		try {
			// Collect all the unrecognized options from the first pass. This will include the
			// (positional) command name, so we need to erase that.
			vector<string> opts = po::collect_unrecognized(parsed.options, po::include_positional);
			opts.erase(opts.begin());
			// Parse again...
			po::store(po::command_line_parser(opts).options(create_desc).run(), vm);
			po::notify(vm);
		}
		catch (po::error& err) {
			throw InvalidCommandSyntaxException(format_error(err.what(), create_desc));
		}

		if (vm.count("application") == 0 && vm.count("site") == 0)
			throw InvalidCommandSyntaxException(format_error("Missing application or site.", create_desc));

		auto category = vm["category"].as<string>();
		auto application = vm.count("application") ? vm["application"].as<string>() : "";
		auto site = vm.count("site") ? vm["site"].as<string>() : "";
		auto username = vm["username"].as<string>();
		auto password = vm["password"].as<string>();
		auto url = vm["url"].as<string>();
		auto description = vm["description"].as<string>();

		return CommandPtr{
				new CreatePasswordCommand{ app, category, application, site, username, password, url, description }};
	}

}
