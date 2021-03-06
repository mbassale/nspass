//
// Created by Marco Bassaletti on 06-03-21.
//

#include "SQLite3Storage.h"
#include <iostream>
#include <vector>
#include <string>
#include "Category.h"
#include "Group.h"

namespace OwnPass::DB {
    using namespace std;

    constexpr auto db_filename = "ownpass.db";

    SQLite3Storage::SQLite3Storage() {
        if (sqlite3_open(db_filename, &connection) != SQLITE_OK) {
            throw std::runtime_error(sqlite3_errmsg(connection));
        }
    }

    SQLite3Storage::~SQLite3Storage() {
        if (sqlite3_close(connection) != SQLITE_OK) {
            std::cerr << "Error closing database: " << sqlite3_errmsg(connection) << std::endl;
        }
    }

    Category &SQLite3Storage::save_category(Category &category) {
        return category;
    }

    std::vector<Category> SQLite3Storage::list_categories() {
        return vector<Category>();
    }

    std::vector<OwnPass::Group> SQLite3Storage::list_groups(Category &category) {
        throw std::runtime_error("Not implemented");
    }

    Category SQLite3Storage::find_category(std::string &search) {
        throw std::runtime_error("Not implemented");
    }

    Group SQLite3Storage::find_group(std::string &search) {
        throw std::runtime_error("Not implemented");
    }
}
