#include "clig.hpp"

namespace cligCore {
  namespace console {
    std::string
    getPassword( const char *prompt ) // Used to get the password of the user without exposing what they typed.
    {
#if defined( _WIN32 ) || defined( _WIN64 )
      std::cout << prompt << std::flush;
      std::string password;
      toggleEcho( false );
      std::cin >> password;
      toggleEcho( true );
      return password;

#elif defined( __unix__ ) || defined( __unix )
      std::string password = getpass( prompt );
      return password;

      (void)tcsetattr( STDIN_FILENO, TCSANOW, &tty );
#endif
    }
  } // namespace console
} // namespace cligCore
