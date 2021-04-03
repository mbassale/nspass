//
// Created by Marco Bassaletti on 02-04-21.
//

#ifndef OWNPASS_UPDATEPASSWORDCOMMANDPARSER_H
#define OWNPASS_UPDATEPASSWORDCOMMANDPARSER_H

#include "../../OwnPass.h"
#include "Parser.h"

namespace OwnPass::CLI::Parsers {
	class UpdatePasswordCommandParser : public Parser {
	public:
		explicit UpdatePasswordCommandParser(OwnPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~UpdatePasswordCommandParser() override = default;

		OwnPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_UPDATEPASSWORDCOMMANDPARSER_H
