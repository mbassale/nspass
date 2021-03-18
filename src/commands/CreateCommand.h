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
		void execute() override;
		void undo() override;

	protected:
		std::string_view category;
		std::string_view application;
		std::string_view site;
		std::string_view username;
		std::string_view password;
		std::string_view url;
		std::string_view description;
	};
}

#endif //OWNPASS_CREATECOMMAND_H
