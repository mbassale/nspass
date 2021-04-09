//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_COPYPASSWORDCOMMAND_H
#define OWNPASS_COPYPASSWORDCOMMAND_H

#include "../NSPass.h"
#include "Command.h"

namespace NSPass::Commands {
	class CopyPasswordCommand : public Command {
	public:
		static constexpr auto Name = "copy-password";
		CopyPasswordCommand(NSPass::Application& app, ObjectId password_id)
				:Command(app), password_id{ password_id } { };
		CopyPasswordCommand(NSPass::Application& app, std::string category_filter, std::string group_filter,
				std::string password_filter)
				:Command(app), category_filter{ std::move(category_filter) }, group_filter{ std::move(group_filter) },
				 password_filter{ std::move(password_filter) } { };
		~CopyPasswordCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }

		[[nodiscard]] std::string_view get_category_filter() const { return category_filter; }
		[[nodiscard]] std::string_view get_group_filter() const { return group_filter; }
		[[nodiscard]] std::string_view get_password_filter() const { return password_filter; }
		[[nodiscard]] PasswordWeakPtr get_copied_password() const { return copied_password; }

		void execute() override;
		void undo() override;
	protected:
		ObjectId password_id{};
		std::string category_filter;
		std::string group_filter;
		std::string password_filter;
		PasswordWeakPtr copied_password;

		PasswordPtr find_first_password();
		PasswordPtr find_first_password_by_id();
		PasswordPtr find_first_password_by_filter();
	};
}

#endif //OWNPASS_COPYPASSWORDCOMMAND_H
