namespace cligCore {
  namespace menu {
    int createMenu( const std::string &title, const std::vector<std::string> &menuContent,
                    const bool &backEnabled ) // Creates a menu without using the nCurses library, not likely to be
    // efficient. Still needs linux code.
    {
      int numberOfOptions = menuContent.size() - 1, pointerCoord = 0;
      printMenu( title, menuContent, pointerCoord, 0 );
      bool failcheck{};
      while ( true ) {
        switch ( getArrowInput() ) {
        case Keys::up: {
          if ( pointerCoord < 0 ) { pointerCoord = numberOfOptions; }
          pointerCoord--;
          printMenu( title, menuContent, pointerCoord, -1 );
          break;
        }
        case Keys::down: {
          pointerCoord++;
          if ( pointerCoord > numberOfOptions ) { pointerCoord = 0; }
          printMenu( title, menuContent, pointerCoord, +1 );
          break;
        }
        case Keys::enter: {
          return pointerCoord;
        }
        case Keys::escape: {
          if ( backEnabled ) { return -1 };
        }
        }
      }
      return -1;
    }
    void printMenu( const std::string &title, const std::vector<std::string> &menuContent, int pointerCoord ) {
      cligCore::console::clear();
      std::cout << termcolor::bold << termcolor::underline << title << termcolor::reset << std::endl;
      for ( int a = 0; a < menuContent.size(); a++ ) {
        if ( pointerCoord == a ) { std::cout << termcolor::on_grey; }
        std::cout << menuContent[ a ] << termcolor::reset << std::endl;
      }
    }
  } // namespace menu
} // namespace cligCore
