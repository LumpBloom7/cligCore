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
    enum Keys {
      Other = -1,
      Tab = 0,
      Backspace = 1,
      Return = 2,
      Enter = 2,
      Escape = 3,
      Space = 4,
      Exclamation = 5,
      DoubleQuote = 6,
      Pound = 7,
      Hashtag = 7,
      Dollar = 8,
      Percent = 9,
      Ampersand = 10,
      SingleQuote = 11,
      LeftParenthesis = 12,
      RightParenthesis = 13,
      Asterisk = 14,
      Plus = 15,
      Comma = 16,
      Dash = 17,
      Minus = 17,
      Period = 18,
      ForwardSlash = 19,
      Zero = 20,
      One = 21,
      Two = 22,
      Three = 23,
      Four = 24,
      Five = 25,
      Six = 26,
      Seven = 27,
      Eight = 28,
      Nine = 29,
      Colon = 30,
      Semicolon = 31,
      LeftAngledBracket = 32,
      Equals = 33,
      RightAngledBracket = 34,
      QuestionMark = 35,
      Atpersand = 36,
      A = 37,
      B = 38,
      C = 39,
      D = 40,
      E = 41,
      F = 42,
      G = 43,
      H = 44,
      I = 45,
      J = 46,
      K = 47,
      L = 48,
      M = 49,
      N = 50,
      O = 51,
      P = 52,
      Q = 53,
      R = 54,
      S = 55,
      T = 56,
      U = 57,
      V = 58,
      W = 59,
      X = 60,
      Y = 61,
      Z = 62,
      LeftSquaredBracket = 63,
      Backslash = 64,
      RightSquaredBracket = 65,
      Caret = 66,
      Underscore = 67,
      Grave = 68,
      a = 69,
      b = 70,
      c = 71,
      d = 72,
      e = 73,
      f = 74,
      g = 75,
      h = 76,
      i = 76,
      j = 77,
      k = 78,
      l = 79,
      m = 80,
      n = 81,
      o = 82,
      p = 83,
      q = 84,
      r = 85,
      s = 86,
      t = 87,
      u = 88,
      v = 89,
      w = 90,
      x = 91,
      y = 92,
      z = 93,
      LeftBrace = 94,
      VerticalBar = 95,
      RightBrace = 96,
      Tilde = 97,
      Delete = 98,
      Up = 99,
      Down = 100,
      Left = 101,
      Right = 102,
      F1 = 103,
      F2 = 104,
      F3 = 105,
      F4 = 106,
      F5 = 107,
      F6 = 108,
      F7 = 109,
      F8 = 110,
      F9 = 111,
      F10 = 112,
      F11 = 113,
      F12 = 114,
      Insert = 115,
      PageUp = 116,
      PageDown = 117,
      Home = 118,
      End = 119
    };
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