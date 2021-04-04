//
// Created by Marco Bassaletti on 04-04-21.
//

#ifndef OWNPASS_DELETEPASSWORDCOMMANDPARSER_H
#define OWNPASS_DELETEPASSWORDCOMMANDPARSER_H

#include "../../OwnPass.h"
#include "Parser.h"

namespace OwnPass::CLI::Parsers {
	class DeletePasswordCommandParser : public Parser {
	public:
		explicit DeletePasswordCommandParser(OwnPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~DeletePasswordCommandParser() override = default;

		OwnPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_DELETEPASSWORDCOMMANDPARSER_H
