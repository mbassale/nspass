//
// Created by Marco Bassaletti on 09-03-21.
//

#ifndef OWNPASS_SITESERIALIZER_H
#define OWNPASS_SITESERIALIZER_H

#include <list>
#include <boost/json.hpp>
#include "GroupSerializer.h"

namespace OwnPass::Storage {
	class SiteSerializer : public JsonSerializer<Site> {
	public:
		static constexpr const char* GroupType = "site";

		boost::json::object serialize(const Site& obj) override;
		boost::json::array serialize(const std::list<Site>& objs) override;

		Site deserialize(boost::json::object& obj) override;
		std::list<Site> deserialize(boost::json::array& objs) override;
	};
}

#endif //OWNPASS_SITESERIALIZER_H
