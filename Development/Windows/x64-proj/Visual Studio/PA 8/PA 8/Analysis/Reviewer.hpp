//
//  Reviewer.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/29/24.
//

#ifndef Reviewer_hpp
#define Reviewer_hpp

#include <vector>

using std::vector;

template <class T>
class Reviewer {
    vector<T> _entities;
    
public:
    Reviewer();
    Reviewer(const vector<T>& entities);
    
    Reviewer(const Reviewer& copy);
    Reviewer operator=(const Reviewer& rhs);
    
    virtual ~Reviewer();
    
    virtual vector<T> entities();
    
    virtual T getMax() = 0;
    virtual T getMin() = 0;
};

#endif /* Reviewer_hpp */
