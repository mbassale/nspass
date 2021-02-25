//
// Created by Marco Bassaletti on 24-02-21.
//

#include "Category.h"

Category& Category::add_group(const std::shared_ptr<Group> &group) {
    groups.push_back(group);
    return *this;
}
