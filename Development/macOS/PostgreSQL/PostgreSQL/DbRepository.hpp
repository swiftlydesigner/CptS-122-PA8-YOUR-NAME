//
//  DbRepository.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/3/24.
//

#ifndef DbRepository_hpp
#define DbRepository_hpp

#include <string>
#include <pqxx/pqxx>

using std::string;

class DbRepository {
    /// Disable copy constructor
    DbRepository(DbRepository& copy) = delete;
    /// Disable = operator
    void operator=(const DbRepository&rhs) = delete;
    
    string url;
    
public:
    /// Construct a controller with a given filled out URL
    /// @Param fullURL The complete server URL for connecting to
    DbRepository(const string& fullURL);
    
    /// Cleanup before destroying obejct
    ~DbRepository();
    
    /// Select all rows from a given table
    pqxx::result selectAllFrom(const string& table) const;
};

#endif /* DbRepository_hpp */
