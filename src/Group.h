//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef OWNPASS_GROUP_H
#define OWNPASS_GROUP_H

#include <string>
#include <list>
#include "Password.h"

namespace OwnPass {
    class Password;

    /**
      * Pure virtual class for Sites and Applications
      */
    class Group {
    public:
        constexpr static const auto DefaultGroupName{ "Default" };

        Group() : name(DefaultGroupName) {}
        Group(const Group& other) : name{ other.name }, passwords{ other.passwords } {}
        Group(Group&& other) noexcept { *this = std::move(other); }
        explicit Group(std::string& name) : name{name} {}
        explicit Group(std::string& name, std::list<Password>& passwords) : name{ name }, passwords{ passwords } {}
        explicit Group(std::string&& name) : name() { this->name = std::move(name); }
        explicit Group(std::string&& name, std::list<Password>&& passwords) : name{}, passwords{} {
            this->name = std::move(name);
            this->passwords = std::move(passwords);
        }
        ~Group() = default;

        Group& operator=(const Group& other) {
            if (this == &other) return *this;
            name = other.name;
            passwords = other.passwords;
            return *this;
        }
        Group& operator=(Group&& other) noexcept {
            name = std::move(other.name);
            passwords.clear();
            passwords = std::move(other.passwords);
            return *this;
        }

        [[nodiscard]] const std::string& get_name() const { return name; }
        Group& set_name(const char* new_name) { name = new_name; return *this; }
        Group& set_name(std::string& new_name) { name = new_name; return *this; }
        [[nodiscard]] const std::list<Password>& get_passwords() const { return passwords; }
        [[nodiscard]] std::list<Password>& get_passwords() { return passwords; }
        Group& add_password(const Password& password);

        static Group& get_default();
    protected:
        std::string name;
        std::list<Password> passwords;
    };
}


#endif //OWNPASS_GROUP_H
