//
// Created by Marco Bassaletti on 17-03-21.
//

#ifndef OWNPASS_CREATEPASSWORDCOMMAND_H
#define OWNPASS_CREATEPASSWORDCOMMAND_H

#include "../NSPass.h"
#include "Command.h"

namespace NSPass::Commands {
	class CreatePasswordCommand : public Command {
	public:
		struct CreateData {
			std::string category;
			std::string application;
			std::string site;
			std::string username;
			std::string password;
			std::string url;
			std::string description;
		};
		static constexpr auto Name = "create";

		CreatePasswordCommand(Application& app, CreateData create_data)
				:Command(app), create_data{ std::move(create_data) } { }
		~CreatePasswordCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }

		[[nodiscard]] CreateData& get_create_data() { return create_data; }

		void execute() override;
		void undo() override;

	protected:
		ObjectId category_id{};
		ObjectId group_id{};
		ObjectId password_id{};
		CreateData create_data{};

		CategoryPtr find_or_create_category();
		GroupPtr find_or_create_group(CategoryPtr& category_obj);
	};
}

#endif //OWNPASS_CREATEPASSWORDCOMMAND_H
