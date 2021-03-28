//
// Created by Marco Bassaletti on 27-03-21.
//

#ifndef OWNPASS_LISTAPPLICATIONSCOMMAND_H
#define OWNPASS_LISTAPPLICATIONSCOMMAND_H

#include "../OwnPass.h"
#include "Command.h"

namespace OwnPass::Commands {
	class ListApplicationsCommand : public Command {
	public:
		static constexpr auto Name = "list-applications";
		explicit ListApplicationsCommand(OwnPass::Application& app)
				:Command(app) { };
		~ListApplicationsCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		void execute() override;
		void undo() override;
	};
}

#endif //OWNPASS_LISTAPPLICATIONSCOMMAND_H
