//
// Created by Marco Bassaletti on 06-03-21.
//

#include "SQLite3Database.h"
#include <vector>
#include <string>
#include "Category.h"
#include "Group.h"

namespace OwnPass::DB {
    SQLite3Database::SQLite3Database() {

    }

    std::vector<OwnPass::Category> SQLite3Database::list_categories() {
        return Database::list_categories();
    }

    std::vector<OwnPass::Group> SQLite3Database::list_groups(Category &category) {
        return Database::list_groups(category);
    }

    Category SQLite3Database::find_category(std::string &search) {
        return Database::find_category(search);
    }

    Group SQLite3Database::find_group(std::string &search) {
        return Database::find_group(search);
    }
}
