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
    LoginController loginController;
    
    vector<Country> countries;
    
    string username;
    
    vector<GoogleReviewEntity> reviews;
    
    /// Login to an account. Set the username and countries.
    /// @Returns Success of login.
    bool login();
    
    /// Called after a successful login.
    /// @Warning Failure to successfully login will result in a crash!
    void getLoginInfo();
    
    /// Fetch all data from the database.
    void fetchDataFromDb();
    
    /// Shows the menu options
    void showMenuOptions() const;
    
public:
    /// Default constructor
    ReviewApp();
    
    /// Delete the copy constructor
    ReviewApp(ReviewApp&copy) = delete;
    /// Delete the = operator
    ReviewApp operator=(ReviewApp& rhs) = delete;
    
    /// Run the application here.
    void runApplication();
};

#endif /* ReviewApp_hpp */
