//
//  DbRepository.cpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/3/24.
//

/// Attention students: Nothing to do here!

#include <iostream>

#include "DbRepository.hpp"

/// Construct a controller with a given filled out URL
/// @Param fullURL The complete server URL for connecting to
DbRepository::DbRepository(const string& fullURL) {
    this->url = fullURL;
}

/// Cleanup before destroying obejct
DbRepository::~DbRepository() {
    
}

/// Select all rows from a given table
/// @Param table The table to read everything from
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

/// Select all fields from a given table
/// @Param fields The fields to select in
/// @Param table The table to read from
/// @Param where Conditionals
pqxx::result DbRepository::selectWhere(const string& fields, const string& table, const string& where) const {
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
        pqxx::result results(nonTrans.exec("SELECT (" + fields + ") FROM " + table + " WHERE (" + where + ");"));
        
        // Print the result
        return results;
        
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return pqxx::result();
}
