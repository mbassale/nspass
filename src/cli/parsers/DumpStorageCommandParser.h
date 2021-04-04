//
// Created by Marco Bassaletti on 27-03-21.
//

#ifndef OWNPASS_DUMPSTORAGECOMMANDPARSER_H
#define OWNPASS_DUMPSTORAGECOMMANDPARSER_H

#include "../../NSPass.h"
#include "Parser.h"

namespace NSPass::CLI::Parsers {
	class DumpStorageCommandParser : public Parser {
	public:
		explicit DumpStorageCommandParser(NSPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~DumpStorageCommandParser() override = default;

		NSPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_DUMPSTORAGECOMMANDPARSER_H
