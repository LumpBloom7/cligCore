#include "clig.hpp"
// Used to get the current Width of the console window
int cligCore::console::getConsoleWidth() {
#if defined( _WIN32 ) || defined( _WIN64 )

  CONSOLE_SCREEN_BUFFER_INFO csbi;
  int columns;
  GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
  columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

  return columns;

#elif defined( __unix__ ) || defined( __unix )

  struct winsize max;
  ioctl( 0, TIOCGWINSZ, &max );
  return max.ws_col;
#endif
}