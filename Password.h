//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef MBASSALE_PM_PASSWORD_H
#define MBASSALE_PM_PASSWORD_H

#include "Group.h"

class Password {
public:
    Password(std::string& username, std::string& password);
    Password(std::string& username, std::string& password, std::string& description);
    Password(Group& group, std::string& username, std::string& password);
    Password(Group& group, std::string& username, std::string& password, std::string& description);
    ~Password();

    [[nodiscard]] const std::string& get_username() const { return username; }
    [[nodiscard]] const std::string& get_password() const { return password; }
    [[nodiscard]] const std::string& get_description() const { return description; }
    [[nodiscard]] const Group& get_group() const { return group; }

private:
    Group& group;
    std::string username;
    std::string password;
    std::string description;
};


#endif //MBASSALE_PM_PASSWORD_H
