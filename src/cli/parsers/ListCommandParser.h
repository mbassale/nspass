//
// Created by Marco Bassaletti on 27-03-21.
//

#ifndef OWNPASS_LISTCOMMANDPARSER_H
#define OWNPASS_LISTCOMMANDPARSER_H

#include "../../NSPass.h"
#include "Parser.h"

namespace NSPass::CLI::Parsers {
	class ListCommandParser : public Parser {
	public:
		explicit ListCommandParser(NSPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:Parser(app, parsed, vm) { }
		~ListCommandParser() override = default;

		NSPass::Commands::CommandPtr operator()();
	};
}

#endif //OWNPASS_LISTCOMMANDPARSER_H
