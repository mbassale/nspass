//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_CATEGORYSERIALIZER_H
#define OWNPASS_CATEGORYSERIALIZER_H

#include "JsonSerializer.h"
#include "../Category.h"
#include <list>
#include <boost/json.hpp>

namespace OwnPass::Storage {
    class CategorySerializer : public JsonSerializer<Category> {
    public:
        CategorySerializer() = default;
        ~CategorySerializer() = default;

        boost::json::object serialize(const Category& obj) override;
        boost::json::array serialize(const std::list<Category>& objs) override;

        Category deserialize(boost::json::object& obj) override;
        std::list<Category> deserialize(boost::json::array& objs) override;
    private:
        std::list<Category> make_default();
    };
}


#endif //OWNPASS_CATEGORYSERIALIZER_H
