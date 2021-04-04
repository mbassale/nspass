//
// Created by Marco Bassaletti on 25-03-21.
//

#include "JsonStorage.h"
#include "JsonStorageFactory.h"

namespace NSPass::Storage {
	std::unique_ptr<Storage> JsonStorageFactory::make(std::string_view master_password, std::string_view storage_filename)
	{
		return std::make_unique<JsonStorage>(master_password, storage_filename);
	}
}
