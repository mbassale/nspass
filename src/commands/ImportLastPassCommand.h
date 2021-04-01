//
// Created by Marco Bassaletti on 01-04-21.
//

#ifndef OWNPASS_IMPORTLASTPASSCOMMAND_H
#define OWNPASS_IMPORTLASTPASSCOMMAND_H

#include "../OwnPass.h"
#include "Command.h"

namespace OwnPass::Commands {
	class ImportLastPassCommand : public Command {
	public:
		static constexpr auto Name = "copy-password";
		ImportLastPassCommand(OwnPass::Application& app, std::string filename)
				:Command(app), filename{ std::move(filename) } { };
		~ImportLastPassCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		bool requires_confirmation() override { return true; }

		[[nodiscard]] std::string_view get_filename() const { return filename; }

		void execute() override;
		void undo() override;
	protected:
		std::string filename;
	};
}

#endif //OWNPASS_IMPORTLASTPASSCOMMAND_H
