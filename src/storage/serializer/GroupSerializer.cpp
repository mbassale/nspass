//
// Created by Marco Bassaletti on 07-03-21.
//
#include <list>
#include <boost/json.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/string_generator.hpp>
#include "../../Group.h"
#include "PasswordSerializer.h"
#include "GroupSerializer.h"

namespace NSPass::Storage::Serializer {
	using namespace std;

	boost::json::object GroupSerializer::serialize(const GroupPtr& obj)
	{
		PasswordSerializer password_serializer{};
		return {
				{ "id", boost::uuids::to_string(obj->get_id()) },
				{ "type", static_cast<int64_t>(obj->get_type()) },
				{ "name", obj->get_name() },
				{ "url", obj->get_url() },
				{ "description", obj->get_description() },
				{ "passwords", password_serializer.serialize(obj->get_passwords()) }
		};
	}

	boost::json::array GroupSerializer::serialize(const vector<GroupPtr>& objs)
	{
		boost::json::array group_data;
		group_data.reserve(objs.size());
		for (auto& group : objs) {
			boost::json::object group_datum = serialize(group);
			group_data.push_back(group_datum);
		}
		return group_data;
	}

	GroupPtr GroupSerializer::deserialize(boost::json::object& obj)
	{
		auto& id_str = obj["id"].as_string();
		boost::uuids::string_generator gen;
		boost::uuids::uuid group_id = gen(id_str.c_str());
		auto group_type = static_cast<GroupType>(obj["type"].as_int64());
		auto& group_name = obj["name"].as_string();
		auto& group_url = obj["url"].as_string();
		auto& group_description = obj["description"].as_string();
		GroupPtr group;
		switch (group_type) {
		case GroupType::Site:
			group = GroupFactory::make_site(group_id, group_name.c_str(), std::vector<PasswordPtr>(), group_url.c_str(),
					group_description.c_str());
			break;
		case GroupType::Application:
			group = GroupFactory::make_application(group_id, group_name.c_str(), std::vector<PasswordPtr>(),
					group_url.c_str(), group_description.c_str());
			break;
		default:
			group = GroupFactory::make_group(group_id, group_name.c_str(), std::vector<PasswordPtr>(), group_url.c_str(),
					group_description.c_str());
			break;
		}

		PasswordSerializer password_serializer{};
		auto& group_passwords = obj["passwords"].as_array();
		auto passwords = password_serializer.deserialize(group_passwords);
		for (auto& password : passwords) {
			group->add_password(password);
		}
		return group;
	}

	std::vector<GroupPtr> GroupSerializer::deserialize(boost::json::array& objs)
	{
		std::vector<GroupPtr> groups;
		groups.reserve(objs.size());
		for (auto val : objs) {
			boost::json::object obj = val.as_object();
			groups.push_back(deserialize(obj));
		}
		return groups;
	}

}
