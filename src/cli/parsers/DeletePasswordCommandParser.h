//
// Created by Marco Bassaletti on 04-04-21.
//

#ifndef OWNPASS_DELETEPASSWORDCOMMANDPARSER_H
#define OWNPASS_DELETEPASSWORDCOMMANDPARSER_H

#include "../../NSPass.h"
#include "Parser.h"

namespace NSPass::CLI::Parsers {
	class DeletePasswordCommandParser : public Parser {
	public:
		explicit DeletePasswordCommandParser(NSPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~DeletePasswordCommandParser() override = default;

		NSPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_DELETEPASSWORDCOMMANDPARSER_H
