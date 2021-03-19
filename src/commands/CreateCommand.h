//
// Created by Marco Bassaletti on 17-03-21.
//

#ifndef OWNPASS_CREATECOMMAND_H
#define OWNPASS_CREATECOMMAND_H

#include "Command.h"

namespace OwnPass::Commands {
	class CreateCommand : public Command {
	public:
		static constexpr auto Name = "create";

		explicit CreateCommand(Application& app, std::string_view category, std::string_view application,
				std::string_view site, std::string_view username, std::string_view password, std::string_view url,
				std::string_view description)
				:Command(app), category{ category }, application{ application }, site{ site }, username{ username },
				 password{ password }, url{ url }, description{ description } { }
		~CreateCommand() override = default;

		std::string_view get_name() override { return Name; }

		[[nodiscard]] std::string_view get_category() const { return category; }
		[[nodiscard]] std::string_view get_application() const { return application; }
		[[nodiscard]] std::string_view get_site() const { return site; }
		[[nodiscard]] std::string_view get_username() const { return username; }
		[[nodiscard]] std::string_view get_password() const { return password; }
		[[nodiscard]] std::string_view get_url() const { return url; }
		[[nodiscard]] std::string_view get_description() const { return description; }

		void execute() override;
		void undo() override;

	protected:
		std::string category;
		std::string application;
		std::string site;
		std::string username;
		std::string password;
		std::string url;
		std::string description;
	};
}

#endif //OWNPASS_CREATECOMMAND_H
