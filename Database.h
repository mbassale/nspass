//
// Created by Marco Bassaletti on 05-03-21.
//

#ifndef OWNPASS_DATABASE_H
#define OWNPASS_DATABASE_H

#include <memory>
#include <string>
#include "Category.h"
#include "Group.h"
#include "Password.h"

namespace OwnPass::DB {

    class Database {
    public:
        virtual std::vector<OwnPass::Category> list_categories();

        virtual std::vector<OwnPass::Group> list_groups(Category &category);

        virtual OwnPass::Category find_category(std::string &search);

        virtual OwnPass::Group find_group(std::string &search);

        static Database& get_instance();

    protected:
        Database() = default;
        static std::unique_ptr<Database> instance;
    };
}

#endif //OWNPASS_DATABASE_H
