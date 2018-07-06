#ifndef RANGE_HPP
#define RANGE_HPP

namespace cligCore {
  namespace types {
    class Range {
    public:
      Range( int value1, int value2 );
      Range();
      int getLower();
      int getUpper();
      void setLower( int value );
      void setUpper( int value );
      void shift( int value );

    private:
      int _lower, _upper;
    };
  } // namespace types
} // namespace cligCore

#endif