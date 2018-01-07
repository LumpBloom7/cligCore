#include "core.hpp"

#include <fstream>
#include <sys/stat.h>
#include "cereal/types/vector.hpp"
#include "cereal/types/string.hpp"
#include "cereal/archives/json.hpp"

// Includes platform specific implementations
#if defined( _WIN32 ) || defined( _WIN64 )
#include "winCore.cpp"
#elif defined( __unix__ ) || defined( __unix )
#include "linuxCore.cpp"
#endif

namespace cligCore {
  namespace filesystem {                           // Functions used to read and modify the file system of the user.
    bool fileExists( const std::string &fileName ) // Used to check if a certain file exists with a certain directory
    {
      struct stat buffer;
      return ( stat( fileName.c_str(), &buffer ) == 0 );
    }
  }
}
