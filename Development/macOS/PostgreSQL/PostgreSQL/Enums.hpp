//
//  Enums.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

#ifndef Enums_h
#define Enums_h

typedef enum : int {
    REVIEW_ID, // text
    URL, // text
    PLACE_ID, // text
    COUNTRY, // text
    ADDRESS, // text
    REVIEWER_NAME, // text
    REVIEWS_BY_REVIEWER, // int8
    PHOTOS_BY_REVIEWER, // text
    REVIEWER_URL, // text
    LOCAL_GUIDE, // bool
    REVIEW_RATING, // int8
    REVIEW, // text
    REVIEW_DATE, // jsonb
    NUMBER_OF_LIKES, // text
    RESPONSE_OF_OWNER, // text
    RESPONSE_DATE, // [NULLABLE] text
    PHOTOS, // [NULLABLE] text
    PLACE_NAME // text
} GOOGLE_REVIEW_COLUMNS;

typedef enum : int {
    ID, // int8
    USERNAME, // text
    PASSWORD, // text
    COUNTRIES, // text
    SALT // uuid
} GOOGLE_LOGIN;

typedef enum : int {
    kUS,
    kGB,
    kIE,
    kDE,
    kCA,
    kBR,
    kFR,
    kAU,
    kUNSPECIFIED
} Country;

#endif /* Enums_h */
