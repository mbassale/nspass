//
// Created by Marco Bassaletti on 27-03-21.
//
#include "CannotUndoException.h"
#include "../query/CategoryQuery.h"
#include "ListCategoriesCommand.h"

namespace OwnPass::Commands {
	using OwnPass::Query::CategoryQuery;

	void ListCategoriesCommand::execute()
	{
		CategoryQuery category_query{ get_storage(), filter.category_filter };
		const auto& categories = category_query.execute();
		std::vector<std::string> headers = { "Category", "# Sites,Apps" };
		const auto out = create_table_output(headers);
		out->print_headers();
		for (const auto& category : categories) {
			std::vector<std::string> row = { std::string(category->get_name()),
											 std::to_string(category->get_groups().size()) };
			out->print_row(row);
		}
	}

	void ListCategoriesCommand::undo()
	{
		throw CannotUndoException();
	}
}
