//
// Created by Marco Bassaletti on 07-03-21.
//
#include <list>
#include <boost/json.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/string_generator.hpp>
#include "../Group.h"
#include "GroupSerializer.h"

namespace OwnPass::Storage {
	using namespace std;

	boost::json::object GroupSerializer::serialize(const Group& obj)
	{
		return {
				{ "id", boost::uuids::to_string(obj.get_id()) },
				{ "type", static_cast<int64_t>(obj.get_type()) },
				{ "name", obj.get_name() },
				{ "url", obj.get_url() },
				{ "description", obj.get_description() }
		};
	}

	boost::json::array GroupSerializer::serialize(const list<Group>& objs)
	{
		boost::json::array group_data;
		for (auto& group : objs) {
			boost::json::object group_datum = serialize(group);
			group_data.push_back(group_datum);
		}
		return group_data;
	}

	OwnPass::Group GroupSerializer::deserialize(boost::json::object& obj)
	{
		auto& id_str = obj["id"].as_string();
		boost::uuids::string_generator gen;
		boost::uuids::uuid group_id = gen(id_str.c_str());
		auto group_type = static_cast<GroupType>(obj["type"].as_int64());
		auto& group_name = obj["name"].as_string();
		auto& group_url = obj["url"].as_string();
		auto& group_description = obj["description"].as_string();
		const auto passwords = std::list<Password>();
		switch (group_type) {
		case GroupType::Site:
			return GroupFactory::make_site(group_id, group_name.c_str(), passwords, group_url.c_str(),
					group_description.c_str());
		case GroupType::Application:
			return GroupFactory::make_application(group_id, group_name.c_str(), passwords, group_url.c_str(),
					group_description.c_str());
		default:
			return GroupFactory::make_group(group_id, group_name.c_str(), passwords, group_url.c_str(),
					group_description.c_str());
		}
	}

	std::list<Group> GroupSerializer::deserialize(boost::json::array& objs)
	{
		std::list<Group> groups;
		for (auto val : objs) {
			boost::json::object obj = val.as_object();
			groups.push_back(deserialize(obj));
		}
		return groups;
	}

}
