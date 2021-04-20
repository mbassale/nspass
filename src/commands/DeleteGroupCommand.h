//
// Created by Marco Bassaletti on 19-04-21.
//

#ifndef NSPASS_DELETEGROUPCOMMAND_H
#define NSPASS_DELETEGROUPCOMMAND_H

#include "../NSPass.h"
#include "Command.h"
#include "../query/GroupQuery.h"

namespace NSPass::Commands {
	class DeleteGroupCommand : public Command {
	public:
		static constexpr auto Name = "delete-group";
		DeleteGroupCommand(NSPass::Application& app, ObjectId group_id)
				:Command(app), group_id{ group_id } { }
		~DeleteGroupCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		bool requires_confirmation() override { return true; }

		[[nodiscard]] GroupWeakPtr get_deleted_group() const { return deleted_group; }

		void execute() override;
		void undo() override;
	protected:
		ObjectId group_id{};
		GroupWeakPtr deleted_group{};

		NSPass::Query::GroupQueryItem find_group();
	};
}

#endif //NSPASS_DELETEGROUPCOMMAND_H
