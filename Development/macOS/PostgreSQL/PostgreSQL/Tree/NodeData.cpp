//
//  NodeData.cpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/18/24.
//

/// Attention students: Nothing to do here!

#include "NodeData.hpp"
#include "../Entities/GoogleReviewEntity.hpp"

/// Constructor for the businessName and entity
NodeData::NodeData(const string& businessName, const GoogleReviewEntity& entity) {
    this->_businessName = businessName;
    
    this->_entities = vector<GoogleReviewEntity>();
    this->_entities.push_back(entity);
}

/// Get the businessName of the node
const string& NodeData::businessName() const noexcept {
    return this->_businessName;
}

/// Get all entities
const vector<GoogleReviewEntity>& NodeData::getAllEntities() const noexcept {
    return this->_entities;
}

void NodeData::addEntity(const GoogleReviewEntity& entity) {
    this->_entities.push_back(entity);
}

void NodeData::removeEntity(const size_t& index) {
    this->_entities.erase(this->_entities.begin() + index);
}
