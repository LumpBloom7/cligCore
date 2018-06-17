namespace cligCore {
  namespace menu {
    void printMenu( const std::string &title, const std::vector<std::string> &menuContent, int pointerCoord ) {
      cligCore::console::clear();
      std::cout << title << termcolor::reset << std::endl;
      for ( int a = 0; a < menuContent.size(); a++ ) {
        if ( pointerCoord == a ) { std::cout << termcolor::green << "> "; }
        std::cout << menuContent[ a ] << std::flush << termcolor::reset << std::endl;
      }
    }

    int createMenu( const std::string &title, const std::vector<std::string> &menuContent,
                    const bool &backEnabled ) // Creates a menu without using the nCurses library, not likely to be
                                              // efficient. Still needs linux code.
    {
#if defined( _WIN32 ) || defined( _WIN64 )
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
          std::string discard;
          std::getline( std::cin, discard );
          return pointerCoord;
        }
        case cligCore::input::Keys::escape: {
          if ( backEnabled ) { return -1; }
        }
        }
      }
      return -1;

#elif defined( __unix__ ) || defined( __unix )
      int numberOfOptions = menuContent.size() - 1, pointerCoord = 0;
      printMenu( title, menuContent, pointerCoord, 0 );
      bool failcheck{};
      while ( true ) {
        switch ( cligCore::input::getArrowInput() ) {
        case cligCore::input::Keys::up: {
          if ( pointerCoord < 0 ) { pointerCoord = numberOfOptions; }
          pointerCoord--;
          printMenu( title, menuContent, pointerCoord, -1 );
          break;
        }
        case cligCore::input::Keys::down: {
          pointerCoord++;
          if ( pointerCoord > numberOfOptions ) { pointerCoord = 0; }
          printMenu( title, menuContent, pointerCoord, +1 );
          break;
        }
        case cligCore::input::Keys::enter: {
          return pointerCoord;
        }
        case cligCore::input::Keys::escape: {
          if ( backEnabled ) { return -1 };
        }
        }
      }
      return -1;
#endif
    }
  } // namespace menu
} // namespace cligCore
