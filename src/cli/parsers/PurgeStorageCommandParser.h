//
// Created by Marco Bassaletti on 21-03-21.
//

#ifndef OWNPASS_PURGESTORAGECOMMANDPARSER_H
#define OWNPASS_PURGESTORAGECOMMANDPARSER_H

#include "../../NSPass.h"
#include "Parser.h"

namespace NSPass::CLI::Parsers {
	class PurgeStorageCommandParser : public Parser {
	public:
		explicit PurgeStorageCommandParser(NSPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~PurgeStorageCommandParser() override = default;

		NSPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_PURGESTORAGECOMMANDPARSER_H
