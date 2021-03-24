//
// Created by Marco Bassaletti on 24-03-21.
//

#include "../../commands/InspectStorageCommand.h"
#include "InspectStorageCommandParser.h"

namespace OwnPass::CLI::Parsers {
	using namespace std;
	using OwnPass::Commands::CommandPtr;
	using OwnPass::Commands::InspectStorageCommand;

	CommandPtr InspectStorageCommandParser::operator()()
	{
		return CommandPtr{ new InspectStorageCommand{ app }};
	}
}
