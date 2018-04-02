namespace cligCore {
  namespace console {
    int getConsoleWidth() // Used to get the current Width of the console window
    {
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      int columns;
      GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
      columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

      return columns;
    }

    int getConsoleHeight() // Used to get the current Height of the console window
    {
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      int rows;
      GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
      rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
      return rows;
    }
    void toggleEcho( const bool &enable ) // Stops the console from printing anything if disabled.
    {
      HANDLE hStdin = GetStdHandle( STD_INPUT_HANDLE );
      DWORD mode;
      GetConsoleMode( hStdin, &mode );

      if ( not enable ) {
        mode &= ~ENABLE_ECHO_INPUT;
      } else {
        mode |= ENABLE_ECHO_INPUT;
      }

      SetConsoleMode( hStdin, mode );
    }
    std::string
    getPassword( const char *prompt ) // Used to get the password of the user without exposing what they typed.
    {
      std::cout << prompt << std::flush;
      std::string password;
      toggleEcho( false );
      std::cin >> password;
      toggleEcho( true );
      return password;
    }
    void clear() // This is used to clear the screen and reset any formatting changes.
    {
      COORD topLeft{0, 0};
      HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
      CONSOLE_SCREEN_BUFFER_INFO screen;
      DWORD written;

      GetConsoleScreenBufferInfo( console, &screen );
      FillConsoleOutputCharacterA( console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written );
      FillConsoleOutputAttribute( console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
                                  screen.dwSize.X * screen.dwSize.Y, topLeft, &written );
      SetConsoleCursorPosition( console, topLeft );
      std::cout << termcolor::reset;
    }
  } // namespace console
} // namespace cligCore
