#ifndef RANGE_HPP
#define RANGE_HPP

namespace cligCore {
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
  } // namespace types
} // namespace cligCore

#endif