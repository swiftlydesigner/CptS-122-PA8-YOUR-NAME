//
//  User.cpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/29/24.
//

#include "User.hpp"

User::User(const std::string& username, const Country country) :
    _username(username),
    _country(country) {}

User::User(const std::string& username, const std::string& country) :
    _username(username),
    _country(stringToCountry(country)) {}

const std::string& User::username() {
    return _username;
}

const Country User::country() {
    return _country;
}
