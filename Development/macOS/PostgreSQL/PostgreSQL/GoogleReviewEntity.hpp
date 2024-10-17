//
//  GoogleReviewEntity.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

#ifndef GoogleReviewEntity_hpp
#define GoogleReviewEntity_hpp

#include <string>
#include <optional>

#include <pqxx/pqxx>

#include "EnumDecoder.hpp"

using std::string;
using std::optional;

class GoogleReviewEntity final {
    string _reviewId;
    string _url;
    string _placeId;
    Country _country;
    string _address;
    string _reviewerName;
    int _reviewsByReviewer;
    string _photosByReviewer;
    string _reviewerUrl;
    bool _localGuide;
    int _reviewRating;
    string _review;
    string _reviewDate;
    int _numberOfLikes;
    optional <string> _responseOfOwner;
    optional <string> _responseDate;
    optional <string> _photos;
    string _businessName;
    
public:
    /// GoogleReviewEntity constructor based on a db query result.
    /// @Param results The results from a prior db query
    GoogleReviewEntity(const pqxx::result& results);
    
    /// Get the reviewId
    string reviewId() const;
    
    /// Get the url
    string url() const;
    
    /// Get the palce ID
    string placeId() const;
    
    /// Get the country
    Country country() const;
    
    /// Get the address
    string address() const;
    
    /// Get the reviewer's name
    string reviewerName() const;
    
    /// Get the count of reviews written by the reviewer
    int reviewsByReviewer() const;
    
    /// Get the number of photos provided by the reviewer
    int photosByReviewer() const;
    
    /// Get the URL of the reviewer
    string reviewerUrl() const;
    
    /// Is this in a local guide?
    bool localGuide() const;
    
    /// Get the rating on a scale of 1-5
    int reviewRating() const;
    
    /// Get the textual representation of the review. Wrapped as optional value, could be empty.
    optional<string> review() const;
    
    /// Get the date the review was submitted
    string reviewDate() const;
    
    /// Get the number of likes this review has
    int numberOfLikes() const;
    
    /// Get the response of the owner. Wrapped as optional value, could be empty.
    optional<string> responseOfOwner() const;
    
    /// Get the response date of the owner. Wrapped as optional value, could be empty.
    optional<string> responseDate() const;
    
    /// Get the URL(s) of photos attached for the review. Wrapped as optional value, could be empty.
    optional<string> photos() const;
    
    /// Get the business name
    string businessName() const;
    
};

#endif /* GoogleReviewEntity_hpp */
