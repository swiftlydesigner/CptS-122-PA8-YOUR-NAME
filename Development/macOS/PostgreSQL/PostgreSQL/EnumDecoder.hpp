//
//  EnumDecoder.hpp
//  PostgreSQL
//
//  Created by main on 10/17/24.
//

#ifndef EnumDecoder_h
#define EnumDecoder_h

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

#endif /* EnumDecoder_h */
