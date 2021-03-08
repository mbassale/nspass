//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef OWNPASS_SITE_H
#define OWNPASS_SITE_H

#include "Group.h"

namespace OwnPass {
	class Site : public Group {
	public:
		explicit Site(const std::string& name) : Group(name) {}
		~Site() = default;
	};
}

#endif //OWNPASS_SITE_H
