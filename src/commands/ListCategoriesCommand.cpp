//
// Created by Marco Bassaletti on 27-03-21.
//
#include <iostream>
#include "../cli/output/TableOutput.h"
#include "CannotUndoException.h"
#include "ListCategoriesCommand.h"

namespace OwnPass::Commands {
	using OwnPass::CLI::Output::TableOutputOptions;
	using OwnPass::CLI::Output::TableOutput;

	void ListCategoriesCommand::execute()
	{
		auto& categories = app.get_vault().get_storage().list_categories();
		TableOutputOptions table_options{ std::cout, ColumnWidth, 0 };
		std::vector<std::string> headers = { "Category", "# Sites,Apps" };
		TableOutput out{ table_options, headers };
		out.print_headers();
		for (auto& category : categories) {
			std::vector<std::string> row = { std::string(category.get_name()),
											 std::to_string(category.get_groups().size()) };
			out.print_row(row);
		}
	}

	void ListCategoriesCommand::undo()
	{
		throw CannotUndoException();
	}
}
