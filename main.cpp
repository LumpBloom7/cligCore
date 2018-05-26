#include <iostream>
#include <string>
#include <vector>
#include "termcolor.hpp"
#include "clig.cpp"

int main() {
  std::vector<std::string> menuContent{"1. Console", "2. Controls", "3. Filesystem", "4. Input", "5. Types", "6. Quit"};

  while ( true ) {
    int result = cligCore::menu::createMenu( "Please select a debug category.", menuContent, false );

    switch ( result ) {
    case 0: cligCore::console::debug(); break;
    case 1: break;
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: exit( 0 );
    }
  }
}
