//
// Created by Marco Bassaletti on 05-03-21.
//
#include <string>
#include "Storage.h"
#include "JsonStorage.h"

namespace OwnPass::DB {
    using namespace OwnPass;
    using namespace std;

    std::shared_ptr<Storage> StorageFactory::make() {
        return std::make_shared<JsonStorage>();
    }

    Storage::~Storage() = default;
}
