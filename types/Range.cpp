namespace cligCore {
  namespace types {
    class Range {
    public:
      Range( int value1, int value2 ) {
        // Differentiate the smaller value from the bigger value to ease processing and to avoid any potential bugs.
        if ( value1 <= value2 ) {
          lower = value1;
          upper = value2;
        } else {
          lower = value2;
          upper = value1;
        }
      }
      Range() : lower( 0 ), upper( 1 ) {}
      int getLower() { return lower; }
      int getUpper() { return upper; }

    private:
      int lower, upper;
    };
  } // namespace types
} // namespace cligCore
