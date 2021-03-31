//
// Created by Marco Bassaletti on 07-03-21.
//

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/string_generator.hpp>
#include "GroupSerializer.h"
#include "CategorySerializer.h"

namespace OwnPass::Storage::Serializer {

	boost::json::object CategorySerializer::serialize(const CategoryPtr& obj)
	{
		GroupSerializer group_serializer;
		return {
				{ "id", boost::uuids::to_string(obj->get_id()) },
				{ "name", obj->get_name() },
				{ "groups", group_serializer.serialize(obj->get_groups()) }
		};
	}

	boost::json::array CategorySerializer::serialize(const std::vector<CategoryPtr>& objs)
	{
		boost::json::array category_data;
		for (auto& category : objs) {
			auto category_datum = serialize(category);
			category_data.push_back(category_datum);
		}
		return category_data;
	}

	CategoryPtr CategorySerializer::deserialize(boost::json::object& obj)
	{
		auto& id_str = obj["id"].as_string();
		boost::uuids::string_generator gen;
		boost::uuids::uuid category_id = gen(id_str.c_str());
		auto& category_name = obj["name"].as_string();
		auto& groups_data = obj["groups"].as_array();
		std::vector<GroupPtr> groups;
		if (!groups_data.empty()) {
			GroupSerializer group_serializer;
			groups = group_serializer.deserialize(groups_data);
		}
		return std::make_shared<Category>(category_id, category_name.c_str(), groups);
	}

	std::vector<CategoryPtr> CategorySerializer::deserialize(boost::json::array& objs)
	{
		std::vector<CategoryPtr> categories;
		categories.reserve(objs.size());
		for (auto category_datum : objs) {
			auto category_obj = category_datum.as_object();
			auto category = deserialize(category_obj);
			categories.push_back(category);
		}
		if (categories.empty()) return make_default();
		return categories;
	}

	std::vector<CategoryPtr> CategorySerializer::make_default()
	{
		return std::vector<CategoryPtr>();
	}

}
