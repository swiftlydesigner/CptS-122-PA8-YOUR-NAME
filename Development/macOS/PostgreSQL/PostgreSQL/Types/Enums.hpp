//
//  Enums.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

/// Attention students: Please do not modify this file.

#ifndef Enums_h
#define Enums_h

typedef enum : int {
    kREVIEW_ID, // text
    kURL, // text
    kPLACE_ID, // text
    kCOUNTRY, // text
    kADDRESS, // text
    kREVIEWER_NAME, // text
    kREVIEWS_BY_REVIEWER, // int8
    kPHOTOS_BY_REVIEWER, // text
    kREVIEWER_URL, // text
    kLOCAL_GUIDE, // bool
    kREVIEW_RATING, // int8
    kREVIEW, // text
    kREVIEW_DATE, // jsonb
    kNUMBER_OF_LIKES, // text
    kRESPONSE_OF_OWNER, // text
    kRESPONSE_DATE, // [NULLABLE] text
    kPHOTOS, // [NULLABLE] text
    kPLACE_NAME // text
} GOOGLE_REVIEW_COLUMNS;

typedef enum : int {
    kID, // int8
    kUSERNAME, // text
    kPASSWORD, // text
    kCOUNTRIES, // text
    kSALT // uuid
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
