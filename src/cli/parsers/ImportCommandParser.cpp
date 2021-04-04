//
// Created by Marco Bassaletti on 01-04-21.
//

#include "../../NSPass.h"
#include "../../commands/HelpCommand.h"
#include "../../commands/ImportLastPassCommand.h"
#include "../InvalidCommandSyntaxException.h"
#include "ImportCommandParser.h"

namespace NSPass::CLI::Parsers {
	using namespace std;
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::HelpCommand;
	using NSPass::Commands::ImportLastPassCommand;
	using NSPass::CLI::InvalidCommandSyntaxException;
	namespace po = boost::program_options;

	CommandPtr ImportCommandParser::operator()()
	{
		po::options_description list_desc{ "Import command options" };
		list_desc.add_options()
				("help,h", "This help")
				("format", po::value<string>()->default_value("lastpass"), "Import file format")
				("filename,f", po::value<string>(), "Import data filename");

		try {
			vector<string> opts = po::collect_unrecognized(parsed.options, po::include_positional);
			po::store(po::command_line_parser(opts).options(list_desc).run(), vm);
			po::notify(vm);
		}
		catch (po::error& err) {
			throw InvalidCommandSyntaxException(format_error(err.what(), list_desc));
		}

		if (vm.empty() || vm.count("help")) {
			return std::make_shared<HelpCommand>(app, list_desc);
		}

		if (vm.count("filename") == 0) {
			throw InvalidCommandSyntaxException(format_error("Missing filename.", list_desc));
		}

		auto filename = vm["filename"].as<string>();
		if (vm.count("format")) {
			auto format = vm["format"].as<string>();
			if (format == "lastpass") {
				return std::make_shared<ImportLastPassCommand>(app, filename);
			}
		}

		throw InvalidCommandSyntaxException(format_error("Missing argument.", list_desc));
	}
}
