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

string LoginController::hashPassword(const string& plainText, const string& salt) {
    const char * key = std::getenv("SECURE_KEY");
    char plain[512];
    char saltStr[512];
    
    strncpy(plain, plainText.c_str(), 512);
    strncpy(saltStr, salt.c_str(), 512);
    
    const size_t resultSize = strlen(key);
    
    char result[resultSize];
    
    for (int i = 0; i < resultSize; ++i) {
        result[i] = key[i] ^ (plainText[i] ^ saltStr[i]);
    }
    
    return string(result);
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
    bool success = true;
    
    QueryResultVector result = this->_service.getLoginDataForUser(username());
    
    string hashedPassword;
    optional<string> password;
    optional<string> salt;
    
    setFieldFromQueryResult(password, "password", result);
    setFieldFromQueryResult(password, "salt", result);
    
    if (!password.has_value() || !salt.has_value()) {
        success = false;
    }
    
    hashedPassword = this->hashPassword(password.value(), salt.value());
    
    return hashedPassword == password;
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
