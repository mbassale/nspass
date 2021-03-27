//
// Created by Marco Bassaletti on 27-03-21.
//

#ifndef OWNPASS_DUMPSTORAGECOMMAND_H
#define OWNPASS_DUMPSTORAGECOMMAND_H

#include "../OwnPass.h"
#include "Command.h"

namespace OwnPass::Commands {
	class DumpStorageCommand : public Command {
	public:
		static constexpr auto Name = "dump";

		explicit DumpStorageCommand(Application& app)
				:Command(app) { }
		~DumpStorageCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		bool requires_confirmation() override { return true; }

		void execute() override;
		void undo() override;
	};
}

#endif //OWNPASS_DUMPSTORAGECOMMAND_H
