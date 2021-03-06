//
// Created by Marco Bassaletti on 06-03-21.
//

#ifndef OWNPASS_SQLITE3STORAGE_H
#define OWNPASS_SQLITE3STORAGE_H

#include "Storage.h"
#include "sqlite3.h"

namespace OwnPass::DB {
    class SQLite3Storage : public Storage {
    public:
        SQLite3Storage();
        ~SQLite3Storage() override;

        Category& save_category(Category& category) override;

        std::vector<OwnPass::Category> list_categories() override;

        std::vector<OwnPass::Group> list_groups(Category &category) override;

        Category find_category(std::string &search) override;

        Group find_group(std::string &search) override;
    private:
        sqlite3* connection{};
    };
}


#endif //OWNPASS_SQLITE3STORAGE_H
