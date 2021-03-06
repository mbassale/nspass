//
// Created by Marco Bassaletti on 06-03-21.
//

#ifndef OWNPASS_SQLITE3DATABASE_H
#define OWNPASS_SQLITE3DATABASE_H

#include "Database.h"

namespace OwnPass::DB {
    class SQLite3Database : public Database {
    public:
        SQLite3Database();

        std::vector<OwnPass::Category> list_categories() override;

        std::vector<OwnPass::Group> list_groups(Category &category) override;

        Category find_category(std::string &search) override;

        Group find_group(std::string &search) override;
    };
}


#endif //OWNPASS_SQLITE3DATABASE_H
