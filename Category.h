//
// Created by Marco Bassaletti on 24-02-21.
//

#ifndef OWNPASS_CATEGORY_H
#define OWNPASS_CATEGORY_H

#include "Group.h"
#include <list>

class Category {
public:
    Category() = default;
    Category(std::list<std::shared_ptr<Group>>& groups) : groups{ groups } {}
    ~Category() = default;

    [[nodiscard]] const std::list<std::shared_ptr<Group>>& get_groups() const { return groups; }
    Category& add_group(const std::shared_ptr<Group>& group);
private:
    std::list<std::shared_ptr<Group>> groups;
};


#endif //OWNPASS_CATEGORY_H
