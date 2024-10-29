//
//  LoginController.cpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

/// TODO: Implement `bool LoginController::attemptLogin()`!

#include "LoginController.hpp"

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

/// MARK: - Public Methods
LoginController::LoginController() : _service("postgresql://introuser.soppzqrbchxgxpaqngld:122pass@aws-0-us-west-1.pooler.supabase.com:6543/postgres") {
    
}

/// Prompt the user for username and password
void LoginController::gatherLoginCreds() {
    clearScreen();
    cout << "Welcome! Please enter your username and password." << endl;
    cout << "Notice: When you type your password, it will be hidden." << endl;
    
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
    }
    
    cout << "username % ";
    getUsernameFromUser();
    hideInput();
    cout << "password % ";
    getPasswordFromUser();
    showInput();
    
    ++loginAttempts;
}

/// Attempt login with the gatheredCredentials
/// @Returns True if the login was ok, false otherwise
bool LoginController::attemptLogin() {
    /// TODO: (Me) Select the row where the username matches
    /// TODO: (Me) Hash the password with salt
    /// TODO: (Student) Compare if the hashed_password == password. Return this value
    return false;
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
