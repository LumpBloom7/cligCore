namespace cligCore {
  namespace control {
    int rangeChooser( int originalValue, std::string &title, types::Range range ) {
      cligCore::console::clear();
      int lower = range.getLower();
      int upper = range.getUpper();
      int current = originalValue;
      std::cout << title << std::endl
                << "Please select a value between " << lower << " and " << upper << "." << std::endl
                << std::endl
                << " < " << current << " > \r" << std::flush;

      bool failsafe = false;
      while ( true ) {
        if ( not failsafe ) {
          cligCore::input::getKeyInput();
          failsafe = true;
        }
        switch ( cligCore::input::getKeyInput() ) {
        case cligCore::input::Keys::right: {
          if ( current < upper ) current++;

          std::cout << " < " << current << " > \r" << std::flush;
          break;
        }
        case cligCore::input::Keys::left: {
          if ( current > lower ) current--;

          std::cout << " < " << current << " > \r" << std::flush;
          break;
        }
        case cligCore::input::Keys::enter: {
          return current;
        }
        case cligCore::input::Keys::escape: {
          return originalValue;
        }
        }
      }
    }
  } // namespace control
} // namespace cligCore
