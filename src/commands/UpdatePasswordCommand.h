//
// Created by Marco Bassaletti on 02-04-21.
//

#ifndef OWNPASS_UPDATEPASSWORDCOMMAND_H
#define OWNPASS_UPDATEPASSWORDCOMMAND_H

#include "../OwnPass.h"
#include "Command.h"

#include <utility>

namespace OwnPass::Commands {
	class UpdatePasswordCommand : public Command {
	public:
		static constexpr auto Name = "update-password";
		UpdatePasswordCommand(OwnPass::Application& app, std::string_view category, std::string_view application,
				std::string_view site, std::string_view username, std::string_view password, std::string_view url,
				std::string_view description)
				:Command(app), category{ category }, application{ application }, site{ site }, username{ username },
				 password{ password }, url{ url }, description{ description } { };
		~UpdatePasswordCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
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

#endif //OWNPASS_UPDATEPASSWORDCOMMAND_H
