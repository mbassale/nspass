//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef OWNPASS_PASSWORD_H
#define OWNPASS_PASSWORD_H

class Group;

class Password {
public:
    Password(Group& group, std::string& username, std::string& password) :
            group{ group }, username{ username }, password{ password } {}
    Password(Group& group, std::string& username, std::string& password, std::string& description) :
            group{ group }, username{ username }, password{ password }, description{ description } {}
    Password(Group& group, std::string&& username, std::string&& password, std::string&& description) :
            group{ group }, username{ std::move(username) }, password{ std::move(password) }, description{ std::move(description) } {}
    ~Password() = default;

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


#endif //OWNPASS_PASSWORD_H
