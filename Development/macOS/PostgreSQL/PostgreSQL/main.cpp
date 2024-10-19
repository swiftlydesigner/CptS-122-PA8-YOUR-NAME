//
//  main.cpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/3/24.
//

/// Attention students: Please do not modify this file.

#include "ReviewApp.hpp"

int main(int argc, const char * argv[]) {
    
    ReviewApp* app = new ReviewApp;
    
    app->runApplication();
    
    delete app;
    
    return 0;
}
