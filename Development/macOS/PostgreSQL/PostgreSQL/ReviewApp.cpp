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
    
}

/// Fetch all data from the database.
void ReviewApp::fetchDataFromDb() {
    
}

/// Shows the menu options
void ReviewApp::showMenuOptions() const {
    
}
