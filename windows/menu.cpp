namespace cligCore {
  namespace menu {
    int createMenu( const std::string &title, const std::vector<std::string> &menuContent, const bool &backEnabled ) {
      int numberOfOptions = menuContent.size() - 1, pointerCoord = 0;
      printMenu( title, menuContent, pointerCoord );
      bool failcheck{};
      while ( true ) {
        if ( not failcheck ) {
          cligCore::input::getKeyInput();
          failcheck = true;
        }
        switch ( cligCore::input::getKeyInput() ) {
        case cligCore::input::Keys::up: {
          pointerCoord--;
          if ( pointerCoord < 0 ) { pointerCoord = numberOfOptions; }
          printMenu( title, menuContent, pointerCoord );
          break;
        }
        case cligCore::input::Keys::down: {
          pointerCoord++;
          if ( pointerCoord > numberOfOptions ) { pointerCoord = 0; }
          printMenu( title, menuContent, pointerCoord );
          break;
        }
        case cligCore::input::Keys::enter: {
          return pointerCoord;
        }
        case cligCore::input::Keys::escape: {
          if ( backEnabled ) { return -1; }
        }
        }
      }
      return -1;
    }
    void printMenu( const std::string &title, const std::vector<std::string> &menuContent, int pointerCoord ) {
      cligCore::console::clear();
      std::cout << title << termcolor::reset << std::endl;
      for ( int a = 0; a < menuContent.size(); a++ ) {
        if ( pointerCoord == a ) { std::cout << termcolor::green << "> "; }
        std::cout << menuContent[ a ] << termcolor::reset << std::endl;
      }
    }
  } // namespace menu
} // namespace cligCore
