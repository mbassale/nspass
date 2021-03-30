//
// Created by Marco Bassaletti on 27-03-21.
//

#ifndef OWNPASS_LISTPASSWORDSCOMMAND_H
#define OWNPASS_LISTPASSWORDSCOMMAND_H

#include "../OwnPass.h"
#include "ListCommand.h"

namespace OwnPass::Commands {
	class ListPasswordsCommand : public ListCommand {
	public:
		static constexpr auto Name = "list-passwords";
		static constexpr auto ColumnWidth = 32;
		explicit ListPasswordsCommand(OwnPass::Application& app, Format format = Format::STDOUT)
				:ListCommand(app, format) { };
		~ListPasswordsCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		void execute() override;
		void undo() override;
	};
}

#endif //OWNPASS_LISTPASSWORDSCOMMAND_H
