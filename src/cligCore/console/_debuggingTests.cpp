#include "clig.hpp"
namespace cligCore {
  namespace console {
    void debug() {
      clear();
      std::cout << "Console window content successfully cleared!" << std::endl << std::endl;

      std::cout << "Console window height is " << getConsoleHeight() << " characters" << std::endl
                << "Console window width is " << getConsoleWidth() << " characters" << std::endl
                << std::endl;

      std::string password = getPassword( "Testing password input, type anything in..\n" );
      std::cout << "The password you entered is: " << password << std::endl << std::endl;
      std::cin.ignore();
      std::cin.ignore();
    }
  } // namespace console
} // namespace cligCore
