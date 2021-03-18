//
// Created by Marco Bassaletti on 18-03-21.
//

#ifndef OWNPASS_VERBOSECOMMAND_H
#define OWNPASS_VERBOSECOMMAND_H

#include "Command.h"

namespace OwnPass::Commands {
	class VerboseCommand : public Command {
	public:
		static constexpr auto Name = "verbose";
		explicit VerboseCommand(OwnPass::Application& app) : Command(app) {};
		~VerboseCommand() override = default;

		std::string_view get_name() override { return Name; }
		void execute() override;
		void undo() override;
	};
}

#endif //OWNPASS_VERBOSECOMMAND_H
