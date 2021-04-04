//
// Created by Marco Bassaletti on 27-03-21.
//

#include "../../NSPass.h"
#include "../../commands/HelpCommand.h"
#include "../../commands/ListCommand.h"
#include "../../commands/ListCategoriesCommand.h"
#include "../../commands/ListGroupsCommand.h"
#include "../../commands/ListPasswordsCommand.h"
#include "../InvalidCommandSyntaxException.h"
#include "ListCommandParser.h"

namespace NSPass::CLI::Parsers {
	using namespace std;
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::HelpCommand;
	using NSPass::Commands::ListCommand;
	using NSPass::Commands::ListCategoriesCommand;
	using NSPass::Commands::ListGroupsCommand;
	using NSPass::Commands::ListPasswordsCommand;
	using NSPass::CLI::InvalidCommandSyntaxException;
	namespace po = boost::program_options;

	CommandPtr ListCommandParser::operator()()
	{
		po::options_description list_desc{ "List command options" };
		list_desc.add_options()
				("help,h", "This help")
				("categories,c", po::value<string>()->implicit_value(""), "List categories")
				("sites,s", po::value<string>()->implicit_value(""), "List sites")
				("applications,a", po::value<string>()->implicit_value(""), "List applications")
				("passwords,p", po::value<string>()->implicit_value(""), "List passwords")
				("format,f", po::value<string>()->default_value("stdout"), "Output Format: stdout (default) or csv");

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

		ListCommand::Format output_format = ListCommand::Format::STDOUT;
		if (vm.count("format")) {
			auto format = vm["format"].as<string>();
			if (format == "stdout") {
				output_format = ListCommand::Format::STDOUT;
			}
			else if (format == "csv") {
				output_format = ListCommand::Format::CSV;
			}
		}

		ListCommand::Filter filter = ListCommand::EmptyFilter;
		if (vm.count("categories")) {
			filter.category_filter = vm["categories"].as<string>();
		}
		if (vm.count("sites")) {
			filter.group_filter = vm["sites"].as<string>();
		}
		if (vm.count("applications")) {
			filter.group_filter = vm["applications"].as<string>();
		}
		if (vm.count("passwords")) {
			filter.password_filter = vm["passwords"].as<string>();
		}

		if (vm.count("passwords")) {
			return CommandPtr{ new ListPasswordsCommand{ app, output_format, filter }};
		}
		else if (vm.count("sites") || vm.count("applications")) {
			if (vm.count("sites")) {
				return CommandPtr{ new ListGroupsCommand{ app, GroupType::Site, output_format, filter }};
			}
			else {
				return CommandPtr{ new ListGroupsCommand{ app, GroupType::Application, output_format, filter }};
			}
		}
		else if (vm.count("categories")) {
			return CommandPtr{ new ListCategoriesCommand{ app, output_format, filter }};
		}
		else {
			throw InvalidCommandSyntaxException(format_error("Missing argument.", list_desc));
		}
	}
}
