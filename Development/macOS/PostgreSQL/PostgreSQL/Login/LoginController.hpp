//
//  LoginController.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

#ifndef LoginController_hpp
#define LoginController_hpp

#include "DbService.hpp"

using std::pair;

class LoginController final {
    DbService _service;
    
    vector<Country> _countries;
    
    string _username;
    string _password;
    
    /// Get the username and store into _username
    void getUsername();
    
    /// Get the password from the user and store into _password
    void getPassword();
    
public:
    LoginController();
    
    LoginController(const LoginController& copy) = delete;
    LoginController operator=(const LoginController& rhs) = delete;
    
    /// Prompt the user for username and password
    void gatherLoginCreds() const;
    
    /// Attempt login with the gatheredCredentials
    /// @Returns True if the login was ok, false otherwise
    bool attemptLogin();
    
    /// Get the username
    /// @Returns Get the username
    string username();
    
    /// Get the countries
    /// @Returns Get the country or countries the user wants
    vector<Country> countries();
};

#endif /* LoginController_hpp */
