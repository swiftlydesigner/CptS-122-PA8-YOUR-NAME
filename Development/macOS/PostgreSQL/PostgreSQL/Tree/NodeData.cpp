//
//  NodeData.cpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/18/24.
//

#include "NodeData.hpp"
#include "../Entities/GoogleReviewEntity.hpp"

/// Constructor for the businessName and entity
NodeData::NodeData(const string& businessName, const GoogleReviewEntity& entity) {
    this->_businessName = businessName;
    
    this->_entities = vector<GoogleReviewEntity>();
    this->_entities.push_back(entity);
}

/// Get the businessName of the node
const string& businessName();

/// Get all entities
const vector<GoogleReviewEntity>& getAllEntities();
