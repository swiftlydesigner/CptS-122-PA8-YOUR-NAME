//
//  Tree.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/18/24.
//

/// Attention students: You should not modify any of the given code! Only build upon what you are given!

/// TODO: Create methods as you need.

#ifndef Tree_hpp
#define Tree_hpp

#include "TreeNode.hpp"

class Tree final {
    /// TODO: Insert necessary members
    
    bool insert(Node& node, const NodeData& newEntity);
    
public:
    Tree();
    
    Tree(const Tree& copy);
    
    Tree operator=(const Tree& rhs);
    
    ~Tree();
    
    bool insert(const NodeData& newEntity);
};

#endif /* Tree_hpp */
