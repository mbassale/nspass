//
// Created by Marco Bassaletti on 22-02-21.
//

#include "Group.h"

namespace OwnPass {
	Group DEFAULT;

	Group& Group::get_default()
	{
		return DEFAULT;
	}

	Group& Group::add_password(const Password& password)
	{
		passwords.push_back(password);
		return *this;
	}
}