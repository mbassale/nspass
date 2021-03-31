//
// Created by Marco Bassaletti on 27-03-21.
//

#ifndef OWNPASS_LISTCATEGORIESCOMMAND_H
#define OWNPASS_LISTCATEGORIESCOMMAND_H

#include <utility>

#include "../OwnPass.h"
#include "ListCommand.h"

namespace OwnPass::Commands {
	class ListCategoriesCommand : public ListCommand {
	public:
		static constexpr auto Name = "list-categories";
		explicit ListCategoriesCommand(OwnPass::Application& app, Format format = Format::STDOUT,
				const std::string& filter = std::string())
				:ListCommand(app, format, filter) { };
		~ListCategoriesCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		void execute() override;
		void undo() override;
	};
}

#endif //OWNPASS_LISTCATEGORIESCOMMAND_H
