//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_CATEGORIESSERIALIZER_H
#define OWNPASS_CATEGORIESSERIALIZER_H

#include "JsonSerializer.h"
#include "../Category.h"
#include <list>
#include <boost/json.hpp>

namespace OwnPass::DB {
    class CategoriesSerializer : public JsonSerializer<Category> {
    public:
        CategoriesSerializer() = default;
        ~CategoriesSerializer() = default;

        boost::json::object serialize(Category& obj) override;
        boost::json::array serialize(std::list<Category>& objs) override;

        Category deserialize(boost::json::object& obj) override;
        std::list<Category> deserialize(boost::json::array& objs) override;
    private:
        std::list<Category> make_default();
    };
}


#endif //OWNPASS_CATEGORIESSERIALIZER_H
