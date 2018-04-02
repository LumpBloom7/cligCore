namespace cligCore {
  namespace console {
    int getConsoleWidth() // Used to get the current Width of the console window
    {
      struct winsize max;
      ioctl( 0, TIOCGWINSZ, &max );
      return max.ws_col;
    }

    int getConsoleHeight() // Used to get the current Height of the console window
    {
      struct winsize max;
      ioctl( 0, TIOCGWINSZ, &max );
      return max.ws.col
    }
    void toggleEcho( const bool &enable ) // Stops the console from printing anything if disabled.
    {
      struct termios tty;
      tcgetattr( STDIN_FILENO, &tty );
      if ( not enable ) {
        tty.c_lflag &= ~ECHO;
      } else {
        tty.c_lflag |= ECHO;
      }

      (void)tcsetattr( STDIN_FILENO, TCSANOW, &tty );
    }
    std::string
    getPassword( const char *prompt ) // Used to get the password of the user without exposing what they typed.
    {
      std::string password = getpass( prompt );
      return password;
    }
    void clear() // This is used to clear the screen and reset any formatting changes.
    {
      std::cout << "\x1B[2J\x1B[H";
      std::cout << termcolor::reset;
    }
  } // namespace console
} // namespace cligCore
