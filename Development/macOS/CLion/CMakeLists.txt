cmake_minimum_required(VERSION 3.29)
project(CLion)

set(CMAKE_CXX_STANDARD 20)

add_executable(PA8 main.cpp
        ReviewApp.cpp
        Database/DbRepository.cpp
        Database/DbService.cpp
        Entities/GoogleReviewEntity.cpp
        Entities/User.cpp
        Login/LoginController.cpp
        Tree/NodeData.cpp
        Tree/Tree.cpp
        Tree/TreeNode.cpp
        Types/Common.cpp
        Analysis/BusinessReviewAnalyzer.cpp)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    # Set the paths to PostgreSQL and libpqxx
    set(PostgreSQL_INCLUDE_DIRS /opt/homebrew/opt/libpq/include)
    set(PQXX_INCLUDE_DIRS /opt/homebrew/opt/libpqxx/include)

    # Set the paths to PostgreSQL and libpqxx libs
    set(PostgreSQL_LIBRARIES /opt/homebrew/Cellar/postgresql@15/15.8_1/lib/libpq.5.15.dylib)
    set(PQXX_LIBRARIES /opt/homebrew/Cellar/libpqxx/7.9.2/lib/libpqxx-7.9.dylib)           # Replace <version> with the actual version
else()
    # Set the paths to PostgreSQL and libpqxx
    set(PostgreSQL_INCLUDE_DIRS  /usr/local/opt/libpq/include)
    set(PQXX_INCLUDE_DIRS  /usr/local/opt/libpqxx/include)

    # Set the paths to PostgreSQL and libpqxx libs
    set(PostgreSQL_LIBRARIES  /usr/local/Cellar/postgresql@15/15.8_1/lib/libpq.5.15.dylib)
    set(PQXX_LIBRARIES  /usr/local/Cellar/libpqxx/7.9.2/lib/libpqxx-7.9.dylib)           # Replace <version> with the actual version
endif()

# Enable static analysis with Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -analyze -Xclang -analyzer-output=plist")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -analyzer-output=html")
endif()

# Include directories for PostgreSQL and libpqxx
include_directories(${PostgreSQL_INCLUDE_DIRS} ${PQXX_INCLUDE_DIRS})

# Link the PostgreSQL and libpqxx libraries
target_link_libraries(PA8 ${PostgreSQL_LIBRARIES} ${PQXX_LIBRARIES})