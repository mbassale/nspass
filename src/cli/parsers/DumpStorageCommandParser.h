//
// Created by Marco Bassaletti on 27-03-21.
//

#ifndef OWNPASS_DUMPSTORAGECOMMANDPARSER_H
#define OWNPASS_DUMPSTORAGECOMMANDPARSER_H

#include "../../OwnPass.h"
#include "Parser.h"

namespace OwnPass::CLI::Parsers {
	class DumpStorageCommandParser : public Parser {
	public:
		explicit DumpStorageCommandParser(OwnPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~DumpStorageCommandParser() override = default;

		OwnPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_DUMPSTORAGECOMMANDPARSER_H
