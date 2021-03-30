//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_COPYPASSWORDCOMMAND_H
#define OWNPASS_COPYPASSWORDCOMMAND_H

#include "Command.h"

namespace OwnPass::Commands {
	class CopyPasswordCommand : Command {
	public:
		static constexpr auto Name = "copy-password";
		explicit CopyPasswordCommand(OwnPass::Application& app)
		:Command(app) { };
		~CopyPasswordCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		void execute() override;
		void undo() override;
	protected:
		std::string category;
		std::string group;
		std::string password_search;
	};
}

#endif //OWNPASS_COPYPASSWORDCOMMAND_H
