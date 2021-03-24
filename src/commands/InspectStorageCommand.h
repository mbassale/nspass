//
// Created by Marco Bassaletti on 24-03-21.
//

#ifndef OWNPASS_INSPECTSTORAGECOMMAND_H
#define OWNPASS_INSPECTSTORAGECOMMAND_H

#include "../OwnPass.h"
#include "Command.h"

namespace OwnPass::Commands {
	class InspectStorageCommand : public Command {
	public:
		static constexpr auto Name = "inspect";
		explicit InspectStorageCommand(OwnPass::Application& app)
				:Command(app) { };
		~InspectStorageCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		void execute() override;
		void undo() override;
	};
}

#endif //OWNPASS_INSPECTSTORAGECOMMAND_H
