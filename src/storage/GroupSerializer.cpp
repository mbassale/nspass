//
// Created by Marco Bassaletti on 07-03-21.
//
#include <list>
#include <string>
#include <boost/json.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/string_generator.hpp>
#include "../Group.h"
#include "GroupSerializer.h"

namespace OwnPass::Storage {
    using namespace std;

    boost::json::object GroupSerializer::serialize(const Group &obj) {
        return {
			{ "id", boost::uuids::to_string(obj.get_id()) },
            { "name", obj.get_name() }
        };
    }

    boost::json::array GroupSerializer::serialize(const list<Group> &objs) {
        boost::json::array group_data;
        for (auto& group : objs) {
            auto group_datum = serialize(group);
            group_data.push_back(group_datum);
        }
        return group_data;
    }

    OwnPass::Group GroupSerializer::deserialize(boost::json::object &obj) {
		auto& id_str = obj["id"].as_string();
		boost::uuids::string_generator gen;
		boost::uuids::uuid group_id = gen(id_str.c_str());
        boost::json::string group_name = obj["name"].as_string();
        Group group{ group_id, group_name.c_str() };
        return group;
    }

    std::list<Group> GroupSerializer::deserialize(boost::json::array &objs) {
        std::list<Group> groups;
        for (auto obj : objs) {
            groups.push_back(deserialize(obj.as_object()));
        }
        return groups;
    }

}