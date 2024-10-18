//
//  ReviewApp.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

#ifndef ReviewApp_hpp
#define ReviewApp_hpp

#include "DbService.hpp"
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
    
    /// MARK: - Begin adding functions here
    
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
