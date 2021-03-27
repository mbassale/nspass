//
// Created by Marco Bassaletti on 27-03-21.
//

#ifndef OWNPASS_SETSTORAGELOCATIONCOMMAND_H
#define OWNPASS_SETSTORAGELOCATIONCOMMAND_H

#include "../OwnPass.h"
#include "../Application.h"
#include "Command.h"

namespace OwnPass::Commands {
	class SetStorageLocationCommand : public Command {
	public:
		static constexpr auto Name = "storage";
		explicit SetStorageLocationCommand(OwnPass::Application& app, std::string_view storage_location)
				:Command(app), storage_location{ storage_location } { };
		~SetStorageLocationCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return false; }
		void execute() override;
		void undo() override;
	protected:
		std::string storage_location;
	};
}

#endif //OWNPASS_SETSTORAGELOCATIONCOMMAND_H
