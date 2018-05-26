#include "clig.hpp"

#include <fstream>
#include <sys/stat.h>

#include "termcolor.hpp"
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

#include "types/_types.cpp"
#include "console/_console.cpp"
#include "filesystem/_filesystem.cpp"
#include "input/_input.cpp"
#include "controls/_controls.cpp"
#include "menu/_menu.cpp"
