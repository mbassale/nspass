//
// Created by Marco Bassaletti on 22-02-21.
//

#include "Group.h"

Group DEFAULT;

Group& Group::get_default() {
    return DEFAULT;
}

Group &Group::add_password(const std::shared_ptr<Password>& password) {
    passwords.push_back(password);
    return *this;
}
