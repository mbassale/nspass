//
// Created by Marco Bassaletti on 21-03-21.
//

#include "../../commands/Command.h"
#include "../../commands/PurgeStorageCommand.h"
#include "PurgeStorageCommandParser.h"

namespace NSPass::CLI::Parsers {
	using NSPass::Commands::Command;
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::PurgeStorageCommand;

	NSPass::Commands::CommandPtr PurgeStorageCommandParser::operator()()
	{
		return CommandPtr{ new PurgeStorageCommand{ app }};
	}
}
