//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef MBASSALE_PM_GROUP_H
#define MBASSALE_PM_GROUP_H

#include <string>

/**
 * Pure virtual class for Sites and Applications
 */
class Group {
public:
    constexpr static const auto DefaultGroupName{ "Default" };

    Group() : name(DefaultGroupName) {}
    Group(std::string& name) : name(name) {}
    ~Group() {}

    [[nodiscard]] const std::string& get_name() const { return name; }

    static Group& get_default();
protected:
    std::string name;
};


#endif //MBASSALE_PM_GROUP_H
