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
		cout << "Categories Count: " << storage.get_categories().size() << endl;
		cout << endl;
	}

	void InspectStorageCommand::undo()
	{
		throw CannotUndoException();
	}
}
