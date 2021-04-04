//
// Created by Marco Bassaletti on 01-04-21.
//

#ifndef OWNPASS_IMPORTCOMMANDPARSER_H
#define OWNPASS_IMPORTCOMMANDPARSER_H

#include "../../NSPass.h"
#include "Parser.h"

namespace NSPass::CLI::Parsers {
	class ImportCommandParser : public Parser {
	public:
		explicit ImportCommandParser(NSPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~ImportCommandParser() override = default;

		NSPass::Commands::CommandPtr operator()();
	};
}


#endif //OWNPASS_IMPORTCOMMANDPARSER_H
