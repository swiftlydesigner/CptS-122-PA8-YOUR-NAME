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
    
    /// Construct a controller with the given information. The URL will be built in the format: `postgresql://[user].[serverId]:[password]@[serverAddr]:[port]/[db-name]`
    /// @Param username User to connect as.
    /// @Param serverId ID of the serer to connect to.
    /// @Param password Password for the user for the specified`username`.
    /// @Param serverAddr The address of the server to connect to.
    /// @Param db The name of the database to connect to.
    DbRepository(const string& username, const string& serverId, const string& password, const string& serverAddr, const string& db);
    
    /// Cleanup before destroying obejct
    ~DbRepository();
    
    
    pqxx::result selectAllFrom(const string& table) const;
};

#endif /* DbRepository_hpp */
