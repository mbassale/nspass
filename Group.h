//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef OWNPASS_GROUP_H
#define OWNPASS_GROUP_H

#include <string>
#include <list>
#include "Password.h"

/**
 * Pure virtual class for Sites and Applications
 */
class Group {
public:
    constexpr static const auto DefaultGroupName{ "Default" };

    Group() : name(DefaultGroupName) {}
    explicit Group(std::string& name) : name(name) {}
    explicit Group(std::string&& name) : name(std::move(name)) {}
    ~Group() = default;

    [[nodiscard]] const std::string& get_name() const { return name; }
    [[nodiscard]] std::list<std::shared_ptr<Password>>& get_passwords() { return passwords; }
    Group& add_password(const std::shared_ptr<Password>& password);

    static Group& get_default();
protected:
    std::string name;
    std::list<std::shared_ptr<Password>> passwords;
};


#endif //OWNPASS_GROUP_H
