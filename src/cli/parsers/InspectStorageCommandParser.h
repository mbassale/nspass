//
// Created by Marco Bassaletti on 24-03-21.
//

#ifndef OWNPASS_INSPECTSTORAGECOMMANDPARSER_H
#define OWNPASS_INSPECTSTORAGECOMMANDPARSER_H

#include "../../OwnPass.h"
#include "Parser.h"

namespace OwnPass::CLI::Parsers {
	class InspectStorageCommandParser : public Parser {
	public:
		explicit InspectStorageCommandParser(OwnPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~InspectStorageCommandParser() override = default;

		OwnPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_INSPECTSTORAGECOMMANDPARSER_H
