//
//  TreeBase.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/23/24.
//

/// Attention students: You should not modify any of the given code!

#ifndef TreeBase_hpp
#define TreeBase_hpp

#include "TreeNode.hpp"

class TreeBase {
protected:
    Node * mpRoot;
    
    virtual bool insert(Node& node, const NodeData& newData);
    
public:
    TreeBase();
    
    TreeBase(const TreeBase& copy);
    
    TreeBase operator=(const TreeBase& rhs);
    
    virtual bool insert(const NodeData& newData);
};
    
    
#endif /* TreeBase_hpp */
