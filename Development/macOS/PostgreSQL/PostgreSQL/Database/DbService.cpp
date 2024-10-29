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
map<std::string, std::string> DbService::getLoginDataForUser(const std::string& username) {
    return {};
}
