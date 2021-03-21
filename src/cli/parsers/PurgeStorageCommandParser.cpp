//
// Created by Marco Bassaletti on 21-03-21.
//

#include "../../commands/Command.h"
#include "../../commands/PurgeStorageCommand.h"
#include "PurgeStorageCommandParser.h"

namespace OwnPass::CLI::Parsers {
	using OwnPass::Commands::Command;
	using OwnPass::Commands::CommandPtr;
	using OwnPass::Commands::PurgeStorageCommand;

	OwnPass::Commands::CommandPtr PurgeStorageCommandParser::operator()()
	{
		return CommandPtr{ new PurgeStorageCommand{ app }};
	}
}
