//
//  ReviewApp.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

/// Attention students: Please do not modify the indicated sections.

/// TODO: Layout ReviewApp

#ifndef ReviewApp_hpp
#define ReviewApp_hpp

#include "Database/DbService.hpp"
#include "Login/LoginController.hpp"

class ReviewApp final {
    /// MARK: - Do not edit the members below
    
    /// The controller which handles user login and authentication.
    LoginController * _loginController;
    
    /// The countries of interest.
    vector<Country> _countries;
    
    /// The username of the current user.
    string _username;
    
    /// Holds all the reviews
    vector<GoogleReviewEntity> _reviews;
    
    /// MARK: - Begin adding members below
    
    /// You must use the following style to define your options:
    vector<string> _options = {
        "Example 1",
        "Example 2"
        /// TODO: Type literal strings here for each option
    };
    
    /// MARK: - Do not edit the functions below
    
    /// Login to an account. Set the username and countries.
    /// @Returns Success of login.
    bool login();
    
    /// Called after a successful login.
    /// @Warning Failure to successfully login will result in a crash!
    void getUserInformation();
    
    /// Fetch all data from the database.
    void fetchDataFromDb();
    
    /// Shows the menu options.
    void showMenuOptions() const;
    
    /// Get the user's selection for the menu option.
    int getMenuOption() const;
    
    /// MARK: - Begin adding functions here
    
    void handleMenuOption(const int selection) const;
    
public:
    /// MARK: - Do not edit the functions below
    /// Default constructor
    ReviewApp();
    
    /// Destructor
    ~ReviewApp();
    
    /// Delete the copy constructor
    ReviewApp(ReviewApp&copy) = delete;
    /// Delete the = operator
    ReviewApp operator=(ReviewApp& rhs) = delete;
    
    /// Run the application here.
    void runApplication();
};

#endif /* ReviewApp_hpp */
