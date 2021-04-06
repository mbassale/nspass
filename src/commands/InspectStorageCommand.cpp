//
// Created by Marco Bassaletti on 24-03-21.
//

#include <iostream>
#include "InspectStorageCommand.h"

namespace NSPass::Commands {
	using namespace std;

	void InspectStorageCommand::execute()
	{
		auto& storage = app.get_vault().get_storage();
		storage.reload();
		auto& header = storage.get_header();
		cout << "Storage Details:" << endl;
		cout << "ID: " << object_id_to_string(header.get_id()) << endl;
		cout << "Email: " << header.get_email() << endl;
		cout << "Created At: " << timestamp_to_string(header.get_created_at()) << endl;
		cout << "Updated At: " << timestamp_to_string(header.get_updated_at()) << endl;
		cout << "Categories Count: " << get_categories_count() << endl;
		cout << "Groups Count: " << get_groups_count() << endl;
		cout << "Passwords Count: " << get_passwords_count() << endl;
		cout << endl;
	}

	void InspectStorageCommand::undo()
	{
		throw CannotUndoException();
	}

	size_t InspectStorageCommand::get_categories_count()
	{
		return get_storage().get_categories().size();
	}

	size_t InspectStorageCommand::get_groups_count()
	{
		size_t groups_count = 0;
		for (auto& category : get_storage().get_categories()) {
			groups_count += category->get_groups().size();
		}
		return groups_count;
	}

	size_t InspectStorageCommand::get_passwords_count()
	{
		size_t passwords_count = 0;
		for (auto& category : get_storage().get_categories()) {
			for (auto& group : category->get_groups()) {
				passwords_count += group->get_passwords().size();
			}
		}
		return passwords_count;
	}
}
