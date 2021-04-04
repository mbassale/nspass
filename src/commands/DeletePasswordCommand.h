//
// Created by Marco Bassaletti on 04-04-21.
//

#ifndef OWNPASS_DELETEPASSWORDCOMMAND_H
#define OWNPASS_DELETEPASSWORDCOMMAND_H

#include "../OwnPass.h"
#include "Command.h"

namespace OwnPass::Commands {
	class DeletePasswordCommand : public Command {
	public:
		struct Filter {
			std::string category_search;
			std::string application_search;
			std::string site_search;
			std::string username_search;
		};
		struct PasswordData {
			ObjectId id{};
			std::string username;
			SecureString password;
			std::string url;
			std::string description;
		};
		static constexpr auto Name = "copy-password";
		DeletePasswordCommand(OwnPass::Application& app, Filter filter)
				:Command(app), filter{ std::move(filter) } { };
		~DeletePasswordCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		[[nodiscard]] const Filter& get_filter() const { return filter; }
		[[nodiscard]] const PasswordData& get_deleted_password_data() const { return deleted_password_data; }

		void execute() override;
		void undo() override;
	protected:
		Filter filter;
		PasswordData deleted_password_data;
	};
}

#endif //OWNPASS_DELETEPASSWORDCOMMAND_H
