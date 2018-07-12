#include "clig.hpp"
namespace cligCore {
  namespace filesystem {                           // Functions used to read and modify the file system of the user.
    bool fileExists( const std::string &fileName ) // Used to check if a certain file exists with a certain directory
    {
      struct stat buffer;
      return ( stat( fileName.c_str(), &buffer ) == 0 );
    }
  } // namespace filesystem
} // namespace cligCore
