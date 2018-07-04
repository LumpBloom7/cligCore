namespace cligCore {
  namespace types {
    class Range {
    public:
      Range( int value1, int value2 ) {
        // Differentiate the smaller value from the bigger value to ease processing and to avoid any potential bugs.
        if ( value1 <= value2 ) {
          _lower = value1;
          _upper = value2;
        } else {
          _lower = value2;
          _upper = value1;
        }
      }
      Range() : _lower( 0 ), _upper( 1 ) {}
      int getLower() { return _lower; }
      int getUpper() { return _upper; }
      void setLower( int value ) { _lower = value; }
      void setUpper( int value ) { _upper = value; }
      void shift( int value ) {
        _lower += value;
        _upper += value;
      }

    private:
      int _lower, _upper;
    };
  } // namespace types
} // namespace cligCore
