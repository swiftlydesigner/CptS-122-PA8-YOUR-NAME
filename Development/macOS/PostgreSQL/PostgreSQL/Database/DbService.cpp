//
//  DbService.cpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

/// Attention students: Nothing to do here!

#include "DbService.hpp"

/// Create a service item to access a database
/// @Param serverAddress The URL, containing auth info for target DB
DbService::DbService(const string& serverAddress) : _repo(serverAddress) {
    
}

/// Get all reviews in the database
vector<GoogleReviewEntity> DbService::getAllReviews() {
    return vector<GoogleReviewEntity>();
}

/// Get reviews in the database with the constraints
/// @Param country The country to filter by
vector<GoogleReviewEntity> DbService::getReviewsWithCountry(Country country) {
    return vector<GoogleReviewEntity>();
}

/// Get the login info for the specified username.
/// @Param username The username to login with
vector< pair<string, optional<string> > > DbService::getLoginDataForUser(const std::string& username) {
    vector< pair<string, optional<string> > > data = {};
    
    pqxx::result result = this->_repo.selectWhere("password, salt, countries", "google_login", "username = '" + username + "'");
    
    const pqxx::row& row = result.front();
    
    data.push_back(make_pair("pw", row["password"].as< optional<string> >()));
    data.push_back(make_pair("country", row["counties"].as< optional<string> >()));
    data.push_back(make_pair("usr", username));
    data.push_back(make_pair("salt", row["salt"].as< optional<string> >()));
    
    return data;
}
