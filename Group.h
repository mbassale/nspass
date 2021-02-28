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
    explicit Group(std::string& name) : name{name} {}
    explicit Group(std::string& name, std::list<Password>& passwords) : name{ name }, passwords{ passwords } {}
    explicit Group(std::string&& name) : name() { this->name = std::move(name); }
    explicit Group(std::string&& name, std::list<Password>&& passwords) : name{}, passwords{} {
        this->name = std::move(name);
        this->passwords = std::move(passwords);
    }
    ~Group() = default;

    [[nodiscard]] const std::string& get_name() const { return name; }
    [[nodiscard]] std::list<Password>& get_passwords() { return passwords; }
    Group& add_password(const Password& password);

    static Group& get_default();
protected:
    std::string name;
    std::list<Password> passwords;
};


#endif //OWNPASS_GROUP_H
