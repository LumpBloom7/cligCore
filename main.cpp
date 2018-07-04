#include <iostream>
#include <string>
#include <vector>
#include "termcolor.hpp"
#include "clig.cpp"

int main() {
  std::ios_base::sync_with_stdio( false ); // Reduces flashing, but introduces other graphical oddities.
  std::vector<std::string> menuContent{
      "1. Console", "2. Controls", "3. Filesystem", "4. Input", "5. Types", "6. Quit",
  };
  cligCore::menu::Menu mainMenu = cligCore::menu::Menu( menuContent );
  while ( true ) {
    int result = mainMenu.showMenu();

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
