#include "Range.hpp"

cligCore::types::Range::Range() : _lower( 0 ), _upper( 1 ) {}
cligCore::types::Range::Range( int value1, int value2 ) {
  // Differentiate the smaller value from the bigger value to ease processing and to avoid any potential bugs.
  if ( value1 <= value2 ) {
    _lower = value1;
    _upper = value2;
  } else {
    _lower = value2;
    _upper = value1;
  }
}

int cligCore::types::Range::getLower() { return _lower; }
int cligCore::types::Range::getUpper() { return _upper; }

void cligCore::types::Range::setLower( int value ) { _lower = value; }
void cligCore::types::Range::setUpper( int value ) { _upper = value; }

void cligCore::types::Range::shift( int value ) {
  _lower += value;
  _upper += value;
}