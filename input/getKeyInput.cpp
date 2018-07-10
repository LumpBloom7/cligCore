namespace cligCore {
  namespace input {
    Keys getKeyInput() {
#if defined( _WIN32 ) || defined( _WIN64 )
      if ( GetAsyncKeyState( VK_DOWN ) & SHRT_MAX ) {
        return Keys::down;
      } else if ( GetAsyncKeyState( VK_UP ) & SHRT_MAX ) {
        return Keys::up;
      } else if ( GetAsyncKeyState( VK_LEFT ) & SHRT_MAX ) {
        return Keys::left;
      } else if ( GetAsyncKeyState( VK_RIGHT ) & SHRT_MAX ) {
        return Keys::right;
      } else if ( GetAsyncKeyState( VK_RETURN ) & SHRT_MAX ) {
        return Keys::enter;
      } else if ( GetAsyncKeyState( VK_ESCAPE ) & SHRT_MAX ) {
        return Keys::escape;
      } else {
        return Keys::extended;
      }

#elif defined( __unix__ ) || defined( __unix )
      int input;
      input = getch();
      switch ( input ) // lets just waste the value
      {
      case 0:
      case 224:
        switch ( getch() ) // Here the actual code for the key is got
        {
        case 72: return Keys::up;
        case 75: return Keys::left;
        case 77: return Keys::right;
        case 80: return Keys::down;
        }
      }
#endif
    }
  } // namespace input
} // namespace cligCore
