//
//  BusinessReviewAnalyzer.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/18/24.
//

/// TODO: Layout BusinessReviewAnalyzer!

#ifndef BusinessReviewAnalyzer_hpp
#define BusinessReviewAnalyzer_hpp

#include "../Entities/GoogleReviewEntity.hpp"

using std::vector;

class BusinessReviewAnalyzer final {
    vector<GoogleReviewEntity> _entites;
    
public:
    BusinessReviewAnalyzer(const vector<GoogleReviewEntity>);
    
    /// TODO: Add your functions for analysis here!
};

#endif /* BusinessReviewAnalyzer_hpp */
