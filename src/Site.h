//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef OWNPASS_SITE_H
#define OWNPASS_SITE_H

#include <string>
#include <list>
#include "Group.h"
#include "Password.h"
#include <boost/uuid/uuid.hpp>

namespace OwnPass {
	class Site : public Group {
	public:
		explicit Site(const std::string& name)
				:Group(name), url{} { }
		Site(const std::string& name, const std::string& url)
				:Group(name), url{ url } { }
		Site(const std::string& name, const std::string& url, std::list<Password>& passwords) :
			Group(name, passwords), url{ url } {}
		Site(boost::uuids::uuid& id, const std::string& name, const std::string& url, std::list<Password>& passwords) :
			Group(id, name, passwords), url{ url } {}
		~Site() = default;

		[[nodiscard]] const std::string& get_url() const { return url; }
		Site& set_url(const std::string& new_url)
		{
			url = new_url;
			return *this;
		}

	protected:
		std::string url;
	};
}

#endif //OWNPASS_SITE_H
