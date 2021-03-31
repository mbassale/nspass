//
// Created by Marco Bassaletti on 27-03-21.
//
#include "CannotUndoException.h"
#include "ListCategoriesCommand.h"

namespace OwnPass::Commands {

	void ListCategoriesCommand::execute()
	{
		auto& categories = app.get_vault().get_storage().get_categories();
		std::vector<std::string> headers = { "Category", "# Sites,Apps" };
		auto out = create_table_output(headers);
		out->print_headers();
		for (auto& category : categories) {
			std::vector<std::string> row = { std::string(category.get_name()),
											 std::to_string(category.get_groups().size()) };
			out->print_row(row);
		}
	}

	void ListCategoriesCommand::undo()
	{
		throw CannotUndoException();
	}
}
