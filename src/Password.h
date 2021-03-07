//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef OWNPASS_PASSWORD_H
#define OWNPASS_PASSWORD_H

#include "Group.h"

namespace OwnPass {
    class Group;

    class Password {
    public:
        Password(const Password& other) : group{ other.group }, username{ other.username }, password{ other.password },
            description{ other.description } {}
        Password(Password&& other) : group{ other.group } { *this = std::move(other); }
        Password(Group &group, std::string &username, std::string &password) :
                group{group}, username{username}, password{password} {}

        Password(Group &group, std::string &username, std::string &password, std::string &description) :
                group{group}, username{username}, password{password}, description{description} {}

        Password(Group &group, std::string &&username, std::string &&password, std::string &&description) :
                group{group}, username{std::move(username)}, password{std::move(password)},
                description{std::move(description)} {}

        ~Password() = default;

        Password& operator=(const Password& other) {
            if (this == &other) return *this;
            username = other.username;
            password = other.password;
            description = other.description;
            return *this;
        }
        Password& operator=(Password&& other) {
            username = std::move(other.username);
            password = std::move(other.password);
            description = std::move(other.description);
            return *this;
        }

        [[nodiscard]] const std::string &get_username() const { return username; }

        [[nodiscard]] const std::string &get_password() const { return password; }

        [[nodiscard]] const std::string &get_description() const { return description; }

        [[nodiscard]] const Group &get_group() const { return group; }

    private:
        Group &group;
        std::string username;
        std::string password;
        std::string description;
    };
}

#endif //OWNPASS_PASSWORD_H
