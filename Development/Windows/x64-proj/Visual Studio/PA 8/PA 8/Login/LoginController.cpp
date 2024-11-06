//
//  LoginController.cpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

/// Attention Students: Nothing to do here!

#include "LoginController.hpp"

/// MARK: - Initalize static members
optional<User> LoginController::_currentUser = std::nullopt;

/// MARK: - Private Methods
/// Get the username from the user and store into _username
void LoginController::getUsernameFromUser() {
    std::getline(std::cin, this->_username);
}

/// Get the password from the user and store into _password
void LoginController::getPasswordFromUser() {
    std::getline(std::cin, this->_password);
}

void LoginController::setFieldFromQueryResult(optional<string>& dest,
                                              const string& field,
                                              const QueryResultVector& results) const {
    for (const auto &curEle : results) {
        if (curEle.first == field) {
            dest = curEle.second;
        }
    }
}

void LoginController::setUser(const QueryResultVector& result) {
    optional<string> countriesRes;
    
    setFieldFromQueryResult(countriesRes, "country", result);
    
    if (countriesRes.has_value()) {
        LoginController::_currentUser = User(username(), countriesRes.value());
    }
    
}

/// MARK: - Public Methods
LoginController::LoginController() : _service("postgresql://introuser.soppzqrbchxgxpaqngld:122pass@aws-0-us-west-1.pooler.supabase.com:6543/postgres") {
    
}

/// Prompt the user for username and password
void LoginController::gatherLoginCreds() {
    clearScreen();
    cout << "Welcome! Please enter your username and password." << endl;
    cout << "Notice: When you type your password, it will be hidden on some systems." << endl;
    
    /// Check if a warning message should be allowed
    if (loginAttempts > 0 && loginAttempts < 3) {
        /// 1 or 2 attempts remaining. Print warning message
        cout << "Wrong username and/or password! Please try again! " <<
        (3 - loginAttempts) <<
        " attempt" << (loginAttempts != 2 ? "s" : "")
        << " remaining!" << endl;
    } else if (loginAttempts >= 3) {
        /// Session is locked. User must close the app.
        cout << "Session locked. Please close the app and try again later." << endl;
        exit(28002);
    }
    
    cout << "username % ";
    getUsernameFromUser();
    hideInput();
    cout << "password % ";
    getPasswordFromUser();
    showInput();
    cout << "\nAuthenticating user `" + username() + "`..." << endl;
    
    ++loginAttempts;
}

/// Attempt login with the gatheredCredentials
/// @Returns True if the login was ok, false otherwise
bool LoginController::attemptLogin() {
    bool success = true;
    
    QueryResultVector result = this->_service.getLoginDataForUser(username());
    
    optional<string> password;
    
    setFieldFromQueryResult(password, "password", result);
    
    if (password.has_value()) {
        success = this->_password == password;
    } else {
        success = false;
    }
    
    if (success) {
        setUser(result);
    }
    
    return success;
}

/// Get the username
/// @Returns Get the username
string LoginController::username() {
    return this->_username;
}

/// Get the countries
/// @Returns Get the country or countries the user wants
vector<Country> LoginController::countries() {
    return this->_countries;
}

/// Get the current user
optional<User> LoginController::getActiveUser() {
    return _currentUser;
}
