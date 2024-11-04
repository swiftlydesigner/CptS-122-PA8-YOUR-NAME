//
//  EnumDecoder.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

/// Attention students: Please do not modify this file.

#ifndef EnumDecoder_h
#define EnumDecoder_h

#include <map>

#include "Enums.hpp"

/// Taken from GPT 4.o-mini
inline Country stringToCountry(const std::string& countryStr) {
    static const std::map<std::string, Country> countryMap = {
        {"US", kUS},
        {"GB", kGB},
        {"IE", kIE},
        {"DE", kDE},
        {"CA", kCA},
        {"BR", kBR},
        {"FR", kFR},
        {"AU", kAU}
    };
    
    auto it = countryMap.find(countryStr);
    if (it != countryMap.end()) {
        return it->second;
    } else {
        return kUNSPECIFIED; // Return kUNSPECIFIED for unrecognized strings
    }
}

inline std::vector<Country> rawStringToCountries(const std::string& countriesStr) {
    std::vector<Country> countries;
    
    std::stringstream ss(countriesStr);
    std::string country;
    
    while (std::getline(ss, country, ',')) {
        countries.push_back(stringToCountry(country));
    }
    
    return countries;
}

#endif /* EnumDecoder_h */
