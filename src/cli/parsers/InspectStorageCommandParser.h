//
// Created by Marco Bassaletti on 24-03-21.
//

#ifndef OWNPASS_INSPECTSTORAGECOMMANDPARSER_H
#define OWNPASS_INSPECTSTORAGECOMMANDPARSER_H

#include "../../NSPass.h"
#include "Parser.h"

namespace NSPass::CLI::Parsers {
	class InspectStorageCommandParser : public Parser {
	public:
		explicit InspectStorageCommandParser(NSPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~InspectStorageCommandParser() override = default;

		NSPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_INSPECTSTORAGECOMMANDPARSER_H
