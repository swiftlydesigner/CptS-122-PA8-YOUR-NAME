//
//  ReviewApp.cpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

#include "ReviewApp.hpp"

/// Default constructor
ReviewApp::ReviewApp() {
    _loginController = new LoginController;
}

ReviewApp::~ReviewApp() {
    if (_loginController) {
        delete _loginController;
    }
}

/// Run the application here.
void ReviewApp::runApplication() {
    int selection = 0;
    bool shouldRun = true;
    
    while (shouldRun) {
        showMenuOptions();
        selection = getMenuOption();
        handleMenuOption(selection);
    }
}

/// Login to an account. Set the username and countries.
/// @Returns Success of login.
bool ReviewApp::login() {
    _loginController->gatherLoginCreds();
    return _loginController->attemptLogin();
}

/// Retrieve the user's username and countries. Then destroy the loginController.
/// @Warning Failure to successfully login will result in a crash!
void ReviewApp::getUserInformation() {
    this->_username = _loginController->username();
    this->_countries = _loginController->countries();
    
    delete _loginController;
    _loginController = nullptr;
}

/// Fetch all data from the database.
void ReviewApp::fetchDataFromDb() {
    
}

/// Shows the menu options
void ReviewApp::showMenuOptions() const {
    clearScreen();
    int lineNumber = 1;
    
    for (const string& option : this->_options) {
        cout << lineNumber << ") " << option << endl;
        ++lineNumber;
    }
}


int ReviewApp::getMenuOption() const {
    bool valid = true;
    int option = 0;
    string input;
    
    do {
        if (!valid) {
            cout << "Invlaid selection: Input must be an integer and within the range 1 - " << (this->_options.size() - 1) << "!" << endl;
        }
        
        cout << "Selection % ";
        std::getline(std::cin, input);
        
        try {
            option = std::stoi(input);
        } catch (std::exception exc) {
            valid = false;
        }
        
        /// Ensure the option is between 1 and size-1, inclusive.
        valid = option > 0 && option < this->_options.size();
    } while (!valid);
    
    return option - 1;
}

/// TODO: Implment this
void ReviewApp::handleMenuOption(const int selection) const {
    /// TODO: Put your application logic here!
    /// Note: If you need the string to describe the action, do
    /// so by accessing this->_options.at(selection).
    /// Note: selection is already the index, do not adjust it!
}
