//
// Created by Marco Bassaletti on 31-03-21.
//

#ifndef OWNPASS_COPYPASSWORDCOMMANDPARSER_H
#define OWNPASS_COPYPASSWORDCOMMANDPARSER_H

#include "../../OwnPass.h"
#include "Parser.h"

namespace OwnPass::CLI::Parsers {
	class CopyPasswordCommandParser : public Parser {
	public:
		CopyPasswordCommandParser(OwnPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~CopyPasswordCommandParser() override = default;

		OwnPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_COPYPASSWORDCOMMANDPARSER_H
