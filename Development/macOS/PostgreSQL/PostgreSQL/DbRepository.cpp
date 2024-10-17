//
//  DbRepository.cpp
//  PostgreSQL
//
//  Created by main on 10/3/24.
//

#include <iostream>

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

/// Select all rows from a given table
pqxx::result DbRepository::selectAllFrom(const string& table) const {
    try {
        // Connect to the database
        pqxx::connection conn(url);
        
        // Check if the connection is open
#ifdef DEBUG
        if (conn.is_open()) {
            std::cout << "Opened database successfully: " << conn.dbname() << std::endl;
        } else {
            std::cout << "Can't open database" << std::endl;
            return pqxx::result();
        }
#else
        if (!conn.is_open()) {
            return pqxx::result();
        }
#endif
        
        // Create a non-transactional object
        pqxx::nontransaction nonTrans(conn);
        
        // Execute a SQL query
        pqxx::result results(nonTrans.exec("SELECT * FROM " + table + ";"));
        
        // Print the result
        return results;
        
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return pqxx::result();
}
