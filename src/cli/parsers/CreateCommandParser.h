//
// Created by Marco Bassaletti on 18-03-21.
//

#ifndef OWNPASS_CREATECOMMANDPARSER_H
#define OWNPASS_CREATECOMMANDPARSER_H

#include <boost/program_options.hpp>
#include "../../Application.h"
#include "../../commands/Command.h"
#include "Parser.h"

namespace OwnPass::CLI::Parsers {
	class CreateCommandParser : public Parser {
	public:
		explicit CreateCommandParser(OwnPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~CreateCommandParser() override = default;

		OwnPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_CREATECOMMANDPARSER_H
