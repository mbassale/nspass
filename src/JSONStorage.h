//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_JSONSTORAGE_H
#define OWNPASS_JSONSTORAGE_H

#include "Storage.h"
#include <vector>
#include "Category.h"
#include "Group.h"
#include <boost/json.hpp>


namespace OwnPass::DB {
    class JSONStorage : public Storage {
    public:
        JSONStorage();
        ~JSONStorage() override;

        std::vector<OwnPass::Category> list_categories() override;
        Category& save_category(Category& category) override;
        Category find_category(std::string& search) override;

        std::vector<OwnPass::Group> list_groups(Category& category) override;
        Group& save_group(Group& group) override;
        Group find_group(std::string& search) override;

    private:
        std::vector<Category> categories;
    };
}


#endif //OWNPASS_JSONSTORAGE_H
