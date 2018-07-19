#ifndef CLIGCORE_H
#define CLIGCORE_H

#include "rang.hpp"

#include <fstream>
#include <sys/stat.h>

#include <string>
#include <vector>
#include <chrono>
#include <thread>

#include <algorithm>

// Includes platform specific headers
#if defined( _WIN32 ) || defined( _WIN64 )
#include "windows.h"
#include <limits.h>
#elif defined( __unix__ ) || defined( __unix )
#include <sys/ioctl.h>
#include <termios.h>
#include <cstdlib>
#include <unistd.h>
#endif

namespace cligCore {

  namespace filesystem {                            // Functions used to read and modify the file system of the user.
    bool fileExists( const std::string &fileName ); // Used to check if a certain file exists with a certain directory
  }

  namespace console {
    void debug();
    int getConsoleWidth();                 // Used to get the current Width of the console window
    int getConsoleHeight();                // Used to get the current Height of the console window
    void toggleEcho( const bool &enable ); // Stops the console from printing anything if disabled.
    std::string
    getPassword( const char *prompt ); // Used to get the password of the user without exposing what they typed.
    void clear();                      // This is used to clear the screen and reset any formatting changes.
  }                                    // namespace console

  namespace input {
    enum Keys { up = 0, down = 1, left = 2, right = 3, enter = 4, escape = 5, extended = 6 };
    Keys getKeyInput();
  } // namespace input

  namespace types {
    class Range {
    public:
      Range( int lowerBounds, int upperBounds, bool isSelectable = false );
      Range( int lowerBounds, int upperBounds, int currentVal );
      Range();
      int getLower();
      int getUpper();
      void setLower( int value );
      void setUpper( int value );
      void shift( int value );
      void showChooser( std::string &title );
      void showChooser( char title[] );
      int getCurrent();

    private:
      int _current;
      int _lower, _upper;
      bool _isSelectable = false;
    };

    class Menu {
    public:
      Menu( std::vector<std::string> &menuContent, std::string &title, int pointerLocation = 0 );
      Menu( std::vector<std::string> &menuContent, char title[], int pointerLocation = 0 );
      int show();

    private:
      void _updateMenu();
      void _printMenu();
      std::string _title;
      std::vector<std::string> &_menuContent;
      int _pointerLocation = 0;
      cligCore::types::Range _visibleRange;
    };

  } // namespace types

} // namespace cligCore

#endif // CORE_H