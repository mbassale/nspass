//
// Created by Marco Bassaletti on 12-04-21.
//

#ifndef NSPASS_UPDATEGROUPCOMMAND_H
#define NSPASS_UPDATEGROUPCOMMAND_H

#include "../NSPass.h"
#include "Command.h"

namespace NSPass::Commands {
	class UpdateGroupCommand : public Command {
	public:
		struct UpdateData {
			std::optional<std::string> name;
			std::optional<std::string> url;
			std::optional<std::string> description;
		};

		static constexpr auto Name = "update-group";
		UpdateGroupCommand(NSPass::Application& app, ObjectId group_id, UpdateData update_data)
				:Command(app), group_id{ group_id }, update_data{ std::move(update_data) } { };
		~UpdateGroupCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }

		[[nodiscard]] const UpdateData& get_update_data() const { return update_data; }
		[[nodiscard]] const GroupWeakPtr& get_updated_group() const { return updated_group; }

		void execute() override;
		void undo() override;

	protected:
		ObjectId group_id{};
		UpdateData update_data;
		GroupWeakPtr updated_group;

		GroupPtr find_first_group_by_id();
	};
}

#endif //NSPASS_UPDATEGROUPCOMMAND_H
