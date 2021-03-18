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

		explicit CreateCommand(Application& app)
				:Command(app) { }
		~CreateCommand() override = default;

		std::string_view get_name() override { return Name; }
		void execute() override;
		void undo() override;
	};
}

#endif //OWNPASS_CREATECOMMAND_H
