//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_JSONSTORAGE_H
#define OWNPASS_JSONSTORAGE_H

#include "Storage.h"
#include <list>
#include "../Category.h"
#include "../Group.h"


namespace OwnPass::DB {
    class JsonStorage : public Storage {
    public:
        JsonStorage();
        ~JsonStorage() override;

        void purge() override;

        std::list<OwnPass::Category> list_categories() override;
        Category& save_category(Category& category) override;
        Category& find_category(std::string& search) override;

        std::list<OwnPass::Group> list_groups(Category& category) override;
        Group& save_group(Group& group) override;
        Group& find_group(std::string& search) override;

    private:
        static constexpr const char* StorageFile = "ownpass.json";
        std::list<Category> categories;
    };
}


#endif //OWNPASS_JSONSTORAGE_H
