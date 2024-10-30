//
//  User.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/29/24.
//

#ifndef User_hpp
#define User_hpp

#include <string>
#include <vector>

#include "../Types/EnumDecoder.hpp"

class User final {
    const std::string _username;
    const std::vector<Country> _countries;
    
    std::vector<Country> _stringToCountries(const std::string& countries);
    
public:
    /// Initalize the user with a username and country
    User(const std::string& username, const Country country);
    
    /// Initalize the user with a username and string version of country.
    User(const std::string& username, const std::string& country);
    
    User(const User& copy);
    
    User operator=(const User& rhs);
    
    /// Get the username of the current user
    const std::string& username();
    
    /// Get the country of the current user
    const std::vector<Country>& countries();
};

#endif /* User_hpp */
