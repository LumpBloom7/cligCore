#include "clig.hpp"

namespace cligCore {
  namespace console {
    void toggleEcho( const bool &enable ) // Stops the console from printing anything if disabled.
    {
#if defined( _WIN32 ) || defined( _WIN64 )

      HANDLE hStdin = GetStdHandle( STD_INPUT_HANDLE );
      DWORD mode;
      GetConsoleMode( hStdin, &mode );

      if ( not enable ) {
        mode &= ~ENABLE_ECHO_INPUT;
      } else {
        mode |= ENABLE_ECHO_INPUT;
      }

      SetConsoleMode( hStdin, mode );

#elif defined( __unix__ ) || defined( __unix )

      struct termios tty;
      tcgetattr( STDIN_FILENO, &tty );
      if ( not enable ) {
        tty.c_lflag &= ~ECHO;
      } else {
        tty.c_lflag |= ECHO;
      }

      (void)tcsetattr( STDIN_FILENO, TCSANOW, &tty );

#endif
    }
  } // namespace console
} // namespace cligCore
