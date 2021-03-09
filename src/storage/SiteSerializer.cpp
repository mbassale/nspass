//
// Created by Marco Bassaletti on 09-03-21.
//
#include "../Site.h"
#include "SiteSerializer.h"

namespace OwnPass::Storage {

	boost::json::object SiteSerializer::serialize(const Site& obj)
	{
		GroupSerializer group_serializer;
		boost::json::object serialized_obj = group_serializer.serialize(obj);
		serialized_obj["type"] = GroupType;
		serialized_obj["url"] = obj.get_url();
		return serialized_obj;
	}

	boost::json::array SiteSerializer::serialize(const std::list<Site>& objs)
	{
		boost::json::array site_data;
		for (auto& site : objs) {
			boost::json::object site_datum = serialize(site);
			site_data.push_back(site_datum);
		}
		return site_data;
	}

	Site SiteSerializer::deserialize(boost::json::object& obj)
	{
		GroupSerializer group_serializer;
		Group group = group_serializer.deserialize(obj);
		auto url = obj["url"].as_string();
		auto id = group.get_id();
		Site site{ id, group.get_name(), url.c_str(), group.get_passwords() };
		return site;
	}

	std::list<Site> SiteSerializer::deserialize(boost::json::array& objs)
	{
		std::list<Site> sites;
		for (auto& obj : objs) {
			sites.push_back(deserialize(obj.as_object()));
		}
		return sites;
	}
}
