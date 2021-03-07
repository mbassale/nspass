//
// Created by Marco Bassaletti on 07-03-21.
//

#include "CategoriesSerializer.h"

namespace OwnPass::DB {

    boost::json::object CategoriesSerializer::serialize(Category& obj) {
        return {
            { "name", obj.get_name() },
            { "groups", nullptr }
        };
    }

    boost::json::array CategoriesSerializer::serialize(std::list<Category>& objs) {
        boost::json::array category_data;
        for (auto& category : objs) {
            auto category_datum = serialize(category);
            category_data.push_back(category_datum);
        }
        return category_data;
    }

    Category CategoriesSerializer::deserialize(boost::json::object& obj) {
        throw std::runtime_error("Not Implemented");
    }

    std::list<Category> CategoriesSerializer::deserialize(boost::json::array& objs) {
        std::list<Category> categories;
        for (auto category_datum : objs) {
            auto category_obj = category_datum.as_object();
            auto category_name = category_obj["name"].as_string();
            Category category{ category_name.c_str() };
            categories.push_back(category);
        }
        if (categories.empty()) return make_default();
        return categories;
    }

    std::list<Category> CategoriesSerializer::make_default() {
        return std::list<Category>();
    }

}