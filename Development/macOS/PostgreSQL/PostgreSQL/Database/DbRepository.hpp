//
//  DbRepository.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/3/24.
//

/// Attention students: Nothing to do here!

#ifndef DbRepository_hpp
#define DbRepository_hpp

#include <string>
#include <pqxx/pqxx>

using std::string;

class DbRepository {
    /// Disable copy constructor
    DbRepository(DbRepository& copy) = delete;
    /// Disable = operator
    DbRepository operator=(const DbRepository&rhs) = delete;
    
    string url;
    
public:
    /// Construct a controller with a given filled out URL
    /// @Param fullURL The complete server URL for connecting to
    DbRepository(const string& fullURL);
    
    /// Cleanup before destroying obejct
    ~DbRepository();
    
    /// Select all rows from a given table
    pqxx::result selectAllFrom(const string& table) const;
    
    /// Select a fields form a row where the conditions are met from the given table
    pqxx::result selectWhere(const string& fields, const string& table, const string& where) const;
};

#endif /* DbRepository_hpp */
