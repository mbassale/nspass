//
// Created by Marco Bassaletti on 27-03-21.
//

#include "../../commands/DumpStorageCommand.h"
#include "DumpStorageCommandParser.h"

namespace NSPass::CLI::Parsers {
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::DumpStorageCommand;

	CommandPtr DumpStorageCommandParser::operator()()
	{
		return CommandPtr{ new DumpStorageCommand{ app }};
	}
}
