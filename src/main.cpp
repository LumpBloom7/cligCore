#include "clig.hpp"

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio( false ); // Reduces flashing, but introduces other graphical oddities.

  std::vector<std::string> menuContent{
      "1. Console", "2. Controls", "3. Filesystem", "4. Input", "5. Types", "6. Quit",
  };
  std::string lol = "Menu";
  cligCore::types::Menu mainMenu( menuContent, lol );
  while ( true ) {
    int result = mainMenu.show();

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
