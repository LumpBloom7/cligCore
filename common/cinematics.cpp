<<<<<<< Updated upstream:core.cpp
#include "core.hpp"

#include <fstream>
#include <sys/stat.h>

#include "termcolor.hpp"

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
  } // namespace filesystem
} // namespace cligCore
=======
namespace cligCore {
  namespace cinematics {
    class Event {
    public:
      unsigned int timeInMilliseconds = 0;
    };
    class TextEvent : public Event {
      std::string text = "";
    };
    void playCinematics( std::vector<Event> timeline ) {
      std::sort( timeline.begin(), timeline.end(), []( unsigned int lhs, unsigned int rhs ) {
        return ( lhs.timeInMilliseconds < rhs.timeInMilliseconds );
      } );
      for ( int a = 0; a < timeline.length(); a++ ) {
        std::cout << timeline[ a ].text;
        std::this_thread::sleep_for( std::chrono::milliseconds( timeline[ a ].timeInMilliseconds ) );
      }
    }
  } // namespace cinematics
} // namespace cligCore
>>>>>>> Stashed changes:common/cinematics.cpp
