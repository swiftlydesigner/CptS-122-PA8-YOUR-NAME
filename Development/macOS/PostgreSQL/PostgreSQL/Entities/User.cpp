//
//  User.cpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/29/24.
//

#include <sstream>

#include "User.hpp"

std::vector<Country> _stringToCountries(const std::string& countries) {
    std::vector<Country> countryList;
    std::stringstream stream(countries);
    std::string ele;
    
    while (std::getline(stream, ele, ',')) {
        countryList.push_back(stringToCountry(ele));
    }
    
    return countryList;
}

User::User(const std::string& username, const Country country) :
    _username(username),
    _countries(country) {}

User::User(const std::string& username, const std::string& country) :
    _username(username),
    _countries(_stringToCountries(country))
{}

User::User(const User& copy) :
    _username(copy._username),
    _countries(copy._countries)
{}

User User::operator=(const User& rhs) {
    return User(rhs);
}

const std::string& User::username() {
    return _username;
}

const std::vector<Country>& User::countries() {
    return _countries;
}
