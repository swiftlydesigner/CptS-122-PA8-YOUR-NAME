//
//  DbService.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

/// Attention students: Nothing to do here!

#ifndef DbService_hpp
#define DbService_hpp

#include <vector>

#include "DbRepository.hpp"
#include "../Entities/GoogleReviewEntity.hpp"

using std::vector;
using std::pair;
using std::make_pair;

using QueryResultVector = vector< pair<string, optional<string> > >;

class DbService final {
    DbRepository _repo;
    
public:
    /// Create a service item to access a database
    /// @Param serverAddress The URL, containing auth info for target DB
    DbService(const string& serverAddress);
    
    /// Get all reviews in the database
    vector<GoogleReviewEntity> getAllReviews();
    
    /// Get reviews in the database with the constraints
    /// @Param country The country to filter by
    vector<GoogleReviewEntity> getReviewsWithCountry(Country country);
    
    /// Get the login data in the form of a vector
    /// @Param username The username to login under
    QueryResultVector getLoginDataForUser(const std::string& username);
};

#endif /* DbService_hpp */
