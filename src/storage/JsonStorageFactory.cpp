//
// Created by Marco Bassaletti on 25-03-21.
//

#include "JsonStorage.h"
#include "JsonStorageFactory.h"

namespace OwnPass::Storage {
	std::unique_ptr<Storage> JsonStorageFactory::make()
	{
		return std::make_unique<JsonStorage>();
	}
}
