//
// Created by Marco Bassaletti on 17-03-21.
//

#ifndef OWNPASS_COMMAND_H
#define OWNPASS_COMMAND_H

#include "../NSPass.h"
#include "../Application.h"
#include "CannotUndoException.h"

namespace NSPass::Commands {

	class Command {
	public:
		explicit Command(NSPass::Application& app)
				:app{ app } { };
		virtual ~Command() = default;

		virtual std::string_view get_name() = 0;
		virtual bool requires_master_password() = 0;
		virtual bool requires_confirmation() { return false; };
		virtual void execute() = 0;
		virtual void undo() = 0;
	protected:
		Application& app;
		NSPass::Signals::SignalContext& get_signal_context() { return app.get_signal_context(); }
		NSPass::Storage::Storage& get_storage() { return app.get_vault().get_storage(); }
	};

	typedef std::shared_ptr<Command> CommandPtr;
}

#endif //OWNPASS_COMMAND_H
