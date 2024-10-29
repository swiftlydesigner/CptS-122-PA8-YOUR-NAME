//
//  User.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/29/24.
//

#ifndef User_hpp
#define User_hpp

#include <string>

#include "../Types/EnumDecoder.hpp"

class User final {
    const std::string _username;
    const Country _country;
    
public:
    /// Initalize the user with a username and country
    User(const std::string& username, const Country country);
    
    /// Initalize the user with a username and string version of country.
    User(const std::string& username, const std::string& country);
    
    /// Get the username of the current user
    const std::string& username();
    
    /// Get the country of the current user
    const Country country();
};

#endif /* User_hpp */
