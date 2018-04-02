#include "clig.hpp"

#include <fstream>
#include <sys/stat.h>

#include "termcolor.hpp"
#include <chrono>
#include <thread>

#include "common/core.cpp" // Include implementations that work cross-platform

// Includes platform specific implementations
#if defined( _WIN32 ) || defined( _WIN64 )
#include "windows/winCore.cpp"
#elif defined( __unix__ ) || defined( __unix )
#include "linux/linuxCore.cpp"
#endif
