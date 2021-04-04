//
// Created by Marco Bassaletti on 02-04-21.
//

#ifndef OWNPASS_UPDATEPASSWORDCOMMAND_H
#define OWNPASS_UPDATEPASSWORDCOMMAND_H

#include "../OwnPass.h"
#include "Command.h"

namespace OwnPass::Commands {
	class UpdatePasswordCommand : public Command {
	public:
		struct Filter {
			std::string category_search;
			std::string application_search;
			std::string site_search;
			std::string username_search;
		};
		struct UpdateData {
			std::optional<std::string> username;
			std::optional<std::string> password;
			std::optional<std::string> url;
			std::optional<std::string> description;
		};

		static constexpr auto Name = "update-password";
		UpdatePasswordCommand(OwnPass::Application& app, Filter filter, UpdateData update_data)
				:Command(app), filter{ std::move(filter) }, update_data{ std::move(update_data) } { };
		~UpdatePasswordCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }

		[[nodiscard]] const Filter& get_filter() const { return filter; }
		[[nodiscard]] const UpdateData& get_update_data() const { return update_data; }
		[[nodiscard]] const PasswordWeakPtr& get_updated_password() const { return updated_password; }

		void execute() override;
		void undo() override;

	protected:
		Filter filter;
		UpdateData update_data;
		PasswordWeakPtr updated_password;
	};
}

#endif //OWNPASS_UPDATEPASSWORDCOMMAND_H
