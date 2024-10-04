//
//  DbController.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/3/24.
//

#ifndef DbController_hpp
#define DbController_hpp

#include <string>

using std::string;

class DbController {
    /// Disable copy constructor
    DbController(DbController& copy) = delete;
    /// Disable = operator
    void operator=(const DbController&rhs) = delete;
    
public:
    /// Construct a controller with a given filled out URL
    /// @Param fullURL The complete server URL for connecting to
    DbController(const string& fullURL);
    
    /// Construct a controller with the given information. The URL will be built in the format: `postgresql://[user].[serverId]:[password]@[serverAddr]:[port]/[db-name]`
    /// @Param username User to connect as.
    /// @Param serverId ID of the serer to connect to.
    /// @Param password Password for the user for the specified`username`.
    /// @Param serverAddr The address of the server to connect to.
    /// @Param db The name of the database to connect to.
    DbController(const string& username, const string& serverId, const string& password, const string& serverAddr, const string& db);
};

#endif /* DbController_hpp */
