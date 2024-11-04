//
//  GoogleReviewEntity.cpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

/// Attention students: Nothing to do here!

#include "GoogleReviewEntity.hpp"

/// GoogleReviewEntity constructor based on a db query result.
/// @Param row A single row from a db query
GoogleReviewEntity::GoogleReviewEntity(const pqxx::row& row) {
    
}

/// Get the reviewId
string GoogleReviewEntity::reviewId() const {
    return _reviewId;
}

/// Get the url
string GoogleReviewEntity::url() const {
    return _url;
}

/// Get the palce ID
string GoogleReviewEntity::placeId() const {
    return _placeId;
}

/// Get the country
Country GoogleReviewEntity::country() const {
    return _country;
}

/// Get the address
string GoogleReviewEntity::address() const {
    return _address;
}

/// Get the reviewer's name
string GoogleReviewEntity::reviewerName() const {
    return _reviewerName;
}

/// Get the count of reviews written by the reviewer
int GoogleReviewEntity::reviewsByReviewer() const {
    return _reviewsByReviewer;
}

/// Get the number of photos provided by the reviewer
int GoogleReviewEntity::photosByReviewer() const {
    try {
        return std::stoi(_photosByReviewer);
    } catch (std::exception ignore) {
        return 0;
    }
}

/// Get the URL of the reviewer
string GoogleReviewEntity::reviewerUrl() const {
    return _reviewerUrl;
}

/// Is this in a local guide?
bool GoogleReviewEntity::localGuide() const {
    return _localGuide;
}

/// Get the rating on a scale of 1-5
int GoogleReviewEntity::reviewRating() const {
    return _reviewRating;
}

/// Get the textual representation of the review. Wrapped as optional value, could be empty.
optional<string> GoogleReviewEntity::review() const {
    return _review;
}

/// Get the date the review was submitted
string GoogleReviewEntity::reviewDate() const {
    return _reviewDate;
}

/// Get the number of likes this review has
int GoogleReviewEntity::numberOfLikes() const {
    return _numberOfLikes;
}

/// Get the response of the owner. Wrapped as optional value, could be empty.
optional<string> GoogleReviewEntity::responseOfOwner() const {
    return _responseOfOwner;
}

/// Get the response date of the owner. Wrapped as optional value, could be empty.
optional<string> GoogleReviewEntity::responseDate() const {
    return _responseDate;
}

/// Get the URL(s) of photos attached for the review. Wrapped as optional value, could be empty.
optional<string> GoogleReviewEntity::photos() const {
    return _photos;
}

/// Get the business name
string GoogleReviewEntity::businessName() const {
    return _businessName;
}
