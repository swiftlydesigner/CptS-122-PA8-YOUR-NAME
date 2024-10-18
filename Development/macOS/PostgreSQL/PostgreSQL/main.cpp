//
//  main.cpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/3/24.
//

#include "ReviewApp.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    ReviewApp* app = new ReviewApp;
    
    app->runApplication();
    
    delete app;
    
    return 0;
}
