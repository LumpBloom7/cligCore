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
