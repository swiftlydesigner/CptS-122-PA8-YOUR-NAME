//
//  NodeData.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/18/24.
//

/// Attention students: Nothing to do here!

#ifndef NodeData_hpp
#define NodeData_hpp

#include <string>
#include <vector>

using std::string;
using std::vector;

/// Forward declartion of `GoogleReviewEntity`
class GoogleReviewEntity;

class NodeData final {
    string _businessName;
    vector<GoogleReviewEntity> _entities;
    
public:
    /// Constructor for the businessName and entity
    NodeData(const string& businessName, const GoogleReviewEntity& entity);
    
    /// Get the businessName of the node
    const string& businessName() const noexcept;
    
    /// Get all entities
    const vector<GoogleReviewEntity>& getAllEntities() const noexcept;
    
    void addEntity(const GoogleReviewEntity& entity);
    
    void removeEntity(const size_t& index);
};

#endif /* NodeData_hpp */
