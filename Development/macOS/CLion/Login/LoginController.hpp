//
//  LoginController.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

/// Attention Students: There is nothing to change here. Please look in the cpp file.

#ifndef LoginController_hpp
#define LoginController_hpp

#include "../Database/DbService.hpp"
#include "../Types/Common.hpp"
#include "../Entities/User.hpp"

using std::pair;

class LoginController final {
    DbService _service;
    
    vector<Country> _countries;
    
    static optional<User> _currentUser;
    
    string _username;
    string _password;
    
    int loginAttempts = 0;
    
    /// Get the username and store into _username
    void getUsernameFromUser();
    
    /// Get the password from the user and store into _password
    void getPasswordFromUser();
    
    void setFieldFromQueryResult(optional<string>& dest,
                                 const string& field,
                                 const QueryResultVector& results) const;
    
    void setUser(const QueryResultVector& result);
    
public:
    LoginController();
    
    /// Delete the copy constructor and = operator.
    LoginController(const LoginController& copy) = delete;
    LoginController operator=(const LoginController& rhs) = delete;
    
    /// Prompt the user for username and password
    void gatherLoginCreds();
    
    /// Attempt login with the gatheredCredentials
    /// @Returns True if the login was ok, false otherwise
    bool attemptLogin();
    
    /// Get the username
    /// @Returns Get the username
    string username();
    
    /// Get the countries
    /// @Returns Get the country or countries the user wants
    vector<Country> countries();
    
    /// Get the current User
    static optional<User> getActiveUser();
};

#endif /* LoginController_hpp */
