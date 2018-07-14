#include "clig.hpp"

void cligCore::console::clear() // This is used to clear the screen and reset any formatting changes.
{
#if defined( _WIN32 ) || defined( _WIN64 )

  COORD topLeft{0, 0};
  HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
  CONSOLE_SCREEN_BUFFER_INFO screen;
  DWORD written;

  GetConsoleScreenBufferInfo( console, &screen );
  FillConsoleOutputCharacterA( console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written );
  FillConsoleOutputAttribute( console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
                              screen.dwSize.X * screen.dwSize.Y, topLeft, &written );
  SetConsoleCursorPosition( console, topLeft );
  std::cout << rang::style::reset;
#elif defined( __unix__ ) || defined( __unix )
  std::cout << "\x1B[2J\x1B[H";
  std::cout << style::reset;
#endif
}