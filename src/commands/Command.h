//
// Created by Marco Bassaletti on 17-03-21.
//

#ifndef OWNPASS_COMMAND_H
#define OWNPASS_COMMAND_H

#include <memory>
#include <string>
#include "../Application.h"

namespace OwnPass::Commands {

	class Command {
	public:
		explicit Command(OwnPass::Application& app) : app{ app } {};
		virtual ~Command() = default;

		virtual std::string_view get_name() = 0;
		virtual void execute() = 0;
		virtual void undo() = 0;
	protected:
		Application& app;
	};

	typedef std::shared_ptr<Command> CommandPtr;
}

#endif //OWNPASS_COMMAND_H
