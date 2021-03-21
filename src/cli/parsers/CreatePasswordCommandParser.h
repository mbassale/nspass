//
// Created by Marco Bassaletti on 18-03-21.
//

#ifndef OWNPASS_CREATEPASSWORDCOMMANDPARSER_H
#define OWNPASS_CREATEPASSWORDCOMMANDPARSER_H

#include <boost/program_options.hpp>
#include "../../Application.h"
#include "../../commands/Command.h"
#include "Parser.h"

namespace OwnPass::CLI::Parsers {
	class CreatePasswordCommandParser : public Parser {
	public:
		explicit CreatePasswordCommandParser(OwnPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~CreatePasswordCommandParser() override = default;

		OwnPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_CREATEPASSWORDCOMMANDPARSER_H
