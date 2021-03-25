//
// Created by Marco Bassaletti on 12-03-21.
//

#include "Vault.h"

namespace OwnPass {

	Vault& Vault::set_master_password(std::string_view new_master_password)
	{
		master_password = new_master_password;
		return *this;
	}


	BaseStorage& Vault::get_storage()
	{
		if (storage) return *storage;
		if (master_password.empty())
			throw ApplicationException("Trying to open storage without master password");
		storage = storage_factory.make();
		storage->open(master_password);
		return *storage;
	}

}
