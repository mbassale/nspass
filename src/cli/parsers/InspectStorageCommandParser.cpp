//
// Created by Marco Bassaletti on 24-03-21.
//

#include "../../commands/InspectStorageCommand.h"
#include "InspectStorageCommandParser.h"

namespace NSPass::CLI::Parsers {
	using namespace std;
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::InspectStorageCommand;

	CommandPtr InspectStorageCommandParser::operator()()
	{
		return CommandPtr{ new InspectStorageCommand{ app }};
	}
}
