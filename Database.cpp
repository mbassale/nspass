//
// Created by Marco Bassaletti on 05-03-21.
//
#include <sqlite3.h>
#include <vector>
#include <string>
#include "Database.h"
#include "Category.h"
#include "Group.h"
#include "SQLite3Database.h"

namespace OwnPass::DB {
    using namespace OwnPass;
    using namespace std;

    unique_ptr<Database> Database::instance;

    Database& OwnPass::DB::Database::get_instance() {
        if (!Database::instance) {
            Database::instance = std::make_unique<SQLite3Database>();
        }
        return *Database::instance;
    }

    std::vector<Category> Database::list_categories() {
        return vector<Category>();
    }

    std::vector<Group> Database::list_groups(Category &category) {
        return vector<Group>();
    }

    Category Database::find_category(std::string &search) {
        return Category();
    }

    Group Database::find_group(std::string &search) {
        return Group();
    }
}
