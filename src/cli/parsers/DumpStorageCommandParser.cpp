//
// Created by Marco Bassaletti on 27-03-21.
//

#include "../../commands/DumpStorageCommand.h"
#include "DumpStorageCommandParser.h"

namespace OwnPass::CLI::Parsers {
	using OwnPass::Commands::CommandPtr;
	using OwnPass::Commands::DumpStorageCommand;

	CommandPtr DumpStorageCommandParser::operator()()
	{
		return CommandPtr{ new DumpStorageCommand{ app }};
	}
}
