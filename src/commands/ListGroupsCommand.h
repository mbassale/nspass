//
// Created by Marco Bassaletti on 27-03-21.
//

#ifndef OWNPASS_LISTGROUPSCOMMAND_H
#define OWNPASS_LISTGROUPSCOMMAND_H

#include "../OwnPass.h"
#include "Command.h"

namespace OwnPass::Commands {
	class ListGroupsCommand : public Command {
	public:
		static constexpr auto Name = "list-groups";
		explicit ListGroupsCommand(OwnPass::Application& app, GroupType group_type = GroupType::Site)
				:Command(app), group_type{ group_type } { };
		~ListGroupsCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		void execute() override;
		void undo() override;
	protected:
		GroupType group_type;
	};
}

#endif //OWNPASS_LISTGROUPSCOMMAND_H
