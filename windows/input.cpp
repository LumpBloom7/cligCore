namespace cligCore {
  namespace input {
    Keys getKeyInput() {
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
      }
    }
  } // namespace input
} // namespace cligCore
