//
// Created by Marco Bassaletti on 21-03-21.
//

#ifndef OWNPASS_PURGESTORAGECOMMAND_H
#define OWNPASS_PURGESTORAGECOMMAND_H

#include "../NSPass.h"
#include "Command.h"

namespace NSPass::Commands {
	class PurgeStorageCommand : public Command {
	public:
		static constexpr auto Name = "purge";

		explicit PurgeStorageCommand(Application& app) : Command(app) { }
		~PurgeStorageCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		bool requires_confirmation() override { return true; }

		void execute() override;
		void undo() override;
	};
}

#endif //OWNPASS_PURGESTORAGECOMMAND_H
