//
//  BusinessReviewAnalyzer.hpp
//  PostgreSQL
//
//  Created by main on 10/18/24.
//

#ifndef BusinessReviewAnalyzer_hpp
#define BusinessReviewAnalyzer_hpp

#include "../Entities/GoogleReviewEntity.hpp"

using std::vector;

class BusinessReviewAnalyzer {
    vector<GoogleReviewEntity> _entites;
    
public:
    BusinessReviewAnalyzer(const vector<GoogleReviewEntity>);
    
    /// TODO: Add your functions for analysis here!
};

#endif /* BusinessReviewAnalyzer_hpp */
