//
// Created by Marco Bassaletti on 05-03-21.
//
#include <sqlite3.h>
#include <vector>
#include <string>
#include "Storage.h"
#include "SQLite3Storage.h"

namespace OwnPass::DB {
    using namespace OwnPass;
    using namespace std;

    std::shared_ptr<Storage> StorageFactory::make() {
        return std::make_shared<SQLite3Storage>();
    }

    Storage::~Storage() = default;
}
