//
// Created by Marco Bassaletti on 24-03-21.
//

#ifndef OWNPASS_INSPECTSTORAGECOMMAND_H
#define OWNPASS_INSPECTSTORAGECOMMAND_H

#include "../NSPass.h"
#include "Command.h"

namespace NSPass::Commands {
	class InspectStorageCommand : public Command {
	public:
		static constexpr auto Name = "inspect";
		explicit InspectStorageCommand(NSPass::Application& app)
				:Command(app) { };
		~InspectStorageCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		void execute() override;
		void undo() override;
	protected:
		size_t get_categories_count();
		size_t get_groups_count();
		size_t get_passwords_count();
	};
}

#endif //OWNPASS_INSPECTSTORAGECOMMAND_H
