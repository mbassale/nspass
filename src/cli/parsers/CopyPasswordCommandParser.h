//
// Created by Marco Bassaletti on 31-03-21.
//

#ifndef OWNPASS_COPYPASSWORDCOMMANDPARSER_H
#define OWNPASS_COPYPASSWORDCOMMANDPARSER_H

#include "../../NSPass.h"
#include "Parser.h"

namespace NSPass::CLI::Parsers {
	class CopyPasswordCommandParser : public Parser {
	public:
		CopyPasswordCommandParser(NSPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~CopyPasswordCommandParser() override = default;

		NSPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_COPYPASSWORDCOMMANDPARSER_H
