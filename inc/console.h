#pragma once
#include "rang.hpp"
#include <string>

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

namespace cligCore::console {
	int getConsoleWidth();                 // Used to get the current Width of the console window
	int getConsoleHeight();                // Used to get the current Height of the console window
	void toggleEcho(const bool& enable); // Stops the console from printing anything if disabled.
	std::string getPassword(const std::string& prompt); // Used to get the password of the user without exposing what they typed.
	void clear();                      // This is used to clear the screen and reset any formatting changes.
	void resetCursor();                // This is used to reset the cursor location back to the top-left.
}