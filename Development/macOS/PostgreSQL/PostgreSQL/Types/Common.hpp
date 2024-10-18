//
//  Common.hpp
//  PostgreSQL
//
//  Created by Kyle Parker on 10/17/24.
//

#ifndef Common_hpp
#define Common_hpp

#include <iostream>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#endif

using std::cout;
using std::endl;

/// These functions will be defined, based on the OS.
void clearScreen();

void hideInput();
void showInput();

#endif /* Common_hpp */
