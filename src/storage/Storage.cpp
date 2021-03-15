//
// Created by Marco Bassaletti on 05-03-21.
//
#include <string>
#include "Storage.h"
#include "JsonStorage.h"

namespace OwnPass::Storage {
	using namespace OwnPass;
	using namespace std;

	Storage& StorageFactory::make()
	{
		static JsonStorage INSTANCE{};
		return INSTANCE;
	}

	Storage::~Storage() = default;
}
