//
// Created by Marco Bassaletti on 01-04-21.
//

#ifndef OWNPASS_IMPORTCOMMANDPARSER_H
#define OWNPASS_IMPORTCOMMANDPARSER_H

#include "../../OwnPass.h"
#include "Parser.h"

namespace OwnPass::CLI::Parsers {
	class ImportCommandParser : public Parser {
	public:
		explicit ImportCommandParser(OwnPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~ImportCommandParser() override = default;

		OwnPass::Commands::CommandPtr operator()();
	};
}


#endif //OWNPASS_IMPORTCOMMANDPARSER_H
