//
//  DbRepository.cpp
//  PostgreSQL
//
//  Created by main on 10/3/24.
//

#include "DbRepository.hpp"

/// Construct a controller with a given filled out URL
/// @Param fullURL The complete server URL for connecting to
DbRepository::DbRepository(const string& fullURL) {
    this->url = fullURL;
}

/// Construct a controller with the given information. The URL will be built in the format: `postgresql://[user].[serverId]:[password]@[serverAddr]:[port]/[db-name]`
/// @Param username User to connect as.
/// @Param serverId ID of the serer to connect to.
/// @Param password Password for the user for the specified`username`.
/// @Param serverAddr The address of the server to connect to.
/// @Param db The name of the database to connect to.
DbRepository::DbRepository(const string& username, const string& serverId, const string& password, const string& serverAddr, const string& db) {
    this->url =
        "postgresql://" + username + "." + serverId +
            ":" + password + "@" + serverAddr + ":5432/" + db;
}

/// Cleanup before destroying obejct
DbRepository::~DbRepository() {
    
}

/// Connect to the database
bool DbRepository::connect() {
    return false;
}

/// Check if the controller is connected to the database
bool DbRepository::isConnected() const {
    return false;
}

/// Return the name of the database we are connected to
const string& DbRepository::getDatabaseName() const {
    return nullptr;
}

/// Close the current database connection
void close() {
    
}
