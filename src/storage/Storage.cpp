//
// Created by Marco Bassaletti on 05-03-21.
//

#include <memory>
#include "Storage.h"
#include "JsonStorage.h"

namespace OwnPass::Storage {
	using namespace OwnPass;
	using namespace std;

	StoragePtr StorageFactory::make()
	{
		return std::make_unique<JsonStorage>();
	}

	Storage::~Storage() = default;
}
