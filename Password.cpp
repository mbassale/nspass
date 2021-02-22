//
// Created by Marco Bassaletti on 22-02-21.
//
#include <string>
#include "Password.h"

Password::Password(std::string &username, std::string &password) :
    group{ Group::get_default() }, username{ username }, password{ password } {
}

Password::Password(std::string& username, std::string& password, std::string& description) :
    group{ Group::get_default() }, username{ username }, password{ password }, description{ description } {
}

Password::Password(Group& group, std::string& username, std::string& password) :
    group{ group }, username{ username }, password{ password }  {
}

Password::Password(Group& group, std::string& username, std::string& password, std::string& description) :
    group{ group }, username{ username }, password{ password }, description{ description } {
}

Password::~Password() {
}
