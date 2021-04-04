//
// Created by Marco Bassaletti on 02-04-21.
//

#include "../../OwnPass.h"
#include "../../commands/HelpCommand.h"
#include "../../commands/UpdatePasswordCommand.h"
#include "../InvalidCommandSyntaxException.h"
#include "UpdatePasswordCommandParser.h"

namespace OwnPass::CLI::Parsers {
	using namespace std;
	using OwnPass::Commands::CommandPtr;
	using OwnPass::Commands::HelpCommand;
	using OwnPass::Commands::UpdatePasswordCommand;
	using OwnPass::CLI::InvalidCommandSyntaxException;
	namespace po = boost::program_options;

	CommandPtr UpdatePasswordCommandParser::operator()()
	{
		po::options_description create_desc{ "Update command options" };
		create_desc.add_options()
				("help,h", "This help")
				("category,c", po::value<string>()->default_value("")->implicit_value(""), "Password Category")
				("application,a", po::value<string>(), "Application name")
				("site,s", po::value<string>(), "Site name")
				("url", po::value<string>()->default_value("")->implicit_value(""), "Site url")
				("description", po::value<string>()->default_value("")->implicit_value(""), "Description")
				("new-username,n", po::value<string>(), "New username")
				("username,u", po::value<string>(), "Username")
				("password,p", po::value<string>(), "Password");

		try {
			vector<string> opts = po::collect_unrecognized(parsed.options, po::include_positional);
			po::store(po::command_line_parser(opts).options(create_desc).run(), vm);
			po::notify(vm);
		}
		catch (po::error& err) {
			throw InvalidCommandSyntaxException(format_error(err.what(), create_desc));
		}

		if (vm.empty() || vm.count("help")) {
			return CommandPtr{ new HelpCommand{ app, create_desc }};
		}

		if (vm.count("username") == 0 || vm.count("password") == 0) {
			throw InvalidCommandSyntaxException(format_error("Missing required username and password.", create_desc));
		}
		if (vm.count("application") == 0 && vm.count("site") == 0) {
			throw InvalidCommandSyntaxException(format_error("Missing application or site.", create_desc));
		}

		UpdatePasswordCommand::Filter filter;
		filter.category_search = vm["category"].as<string>();
		filter.application_search = vm.count("application") ? vm["application"].as<string>() : "";
		filter.site_search = vm.count("site") ? vm["site"].as<string>() : "";
		filter.username_search = vm["username"].as<string>();

		UpdatePasswordCommand::UpdateData update_data;
		update_data.username = vm.count("new-username") ? std::optional<string>{ vm["new-username"].as<string>() }
														: std::nullopt;
		update_data.password = vm.count("password") ? std::optional<string>{ vm["password"].as<string>() }
													: std::nullopt;
		update_data.url = vm.count("url") ? std::optional<string>{ vm["url"].as<string>() } : std::nullopt;
		update_data.description = vm.count("description") ? std::optional<string>{ vm["description"].as<string>() }
														  : std::nullopt;

		return CommandPtr{ new UpdatePasswordCommand{ app, filter, update_data }};
	}
}
