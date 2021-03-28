//
// Created by Marco Bassaletti on 27-03-21.
//

#ifndef OWNPASS_LISTPASSWORDSCOMMAND_H
#define OWNPASS_LISTPASSWORDSCOMMAND_H

#include "../OwnPass.h"
#include "Command.h"

namespace OwnPass::Commands {
	class ListPasswordsCommand : public Command {
	public:
		static constexpr auto Name = "list-passwords";
		explicit ListPasswordsCommand(OwnPass::Application& app)
				:Command(app) { };
		~ListPasswordsCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		void execute() override;
		void undo() override;
	};
}

#endif //OWNPASS_LISTPASSWORDSCOMMAND_H
