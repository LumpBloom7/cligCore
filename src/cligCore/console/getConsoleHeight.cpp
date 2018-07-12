#include "clig.hpp"

namespace cligCore {
  namespace console {
    // Used to get the current Height of the console window
    int getConsoleHeight() {
#if defined( _WIN32 ) || defined( _WIN64 )
#include "windows.h"
#include <limits.h>
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      int rows;
      GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
      rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
      return rows;
#elif defined( __unix__ ) || defined( __unix )
#include <sys/ioctl.h>
#include <termios.h>
#include <cstdlib>
#include <unistd.h>
      struct winsize max;
      ioctl( 0, TIOCGWINSZ, &max );
      return max.ws.col
#endif
    }
  } // namespace console
} // namespace cligCore
