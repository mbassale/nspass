//
// Created by Marco Bassaletti on 19-04-21.
//

#ifndef NSPASS_CREATEGROUPCOMMAND_H
#define NSPASS_CREATEGROUPCOMMAND_H

#include "Command.h"

namespace NSPass::Commands {
	class CreateGroupCommand : public Command {
	public:
		struct CreateData {
			ObjectId category_id{};
			std::string name;
			std::string url;
			std::string description;
		};
		static constexpr auto Name = "create-group";

		CreateGroupCommand(Application& app, CreateData create_data)
				:Command(app), create_data{ std::move(create_data) } { }
		~CreateGroupCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }

		[[nodiscard]] CreateData& get_create_data() { return create_data; }
		[[nodiscard]] GroupWeakPtr get_created_group() { return created_group; }

		void execute() override;
		void undo() override;

	protected:
		CreateData create_data{};
		GroupWeakPtr created_group{};

		CategoryPtr find_category();
	};
}

#endif //NSPASS_CREATEGROUPCOMMAND_H
