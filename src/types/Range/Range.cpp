#include "Range.hpp"

cligCore::types::Range::Range() : _lower( 0 ), _upper( 10 ), _current( 0 ), _isSelectable( false ) {}
cligCore::types::Range::Range( int lowerBounds, int upperBounds, bool isSelectable ) {
  // Differentiate the smaller value from the bigger value to ease processing and to avoid any potential bugs.
  if ( lowerBounds <= upperBounds ) {
    _lower = lowerBounds;
    _upper = upperBounds;
  } else {
    _lower = upperBounds;
    _upper = lowerBounds;
  }
  if ( isSelectable ) {
    _isSelectable = true;
    _current = _lower;
  }
}
cligCore::types::Range::Range( int lowerBounds, int upperBounds, int currentVal ) {
  // Differentiate the smaller value from the bigger value to ease processing and to avoid any potential bugs.
  if ( lowerBounds <= upperBounds ) {
    _lower = lowerBounds;
    _upper = upperBounds;
  } else {
    _lower = upperBounds;
    _upper = lowerBounds;
  }
  _isSelectable = true;
  if ( currentVal >= _lower && currentVal <= _upper )
    _current = currentVal;
  else
    _current = _lower;
}
int cligCore::types::Range::getLower() { return _lower; }
int cligCore::types::Range::getUpper() { return _upper; }

void cligCore::types::Range::setLower( int value ) { _lower = value; }
void cligCore::types::Range::setUpper( int value ) { _upper = value; }

void cligCore::types::Range::shift( int value ) {
  _lower += value;
  _upper += value;
}

void cligCore::types::Range::showChooser( std::string &title ) {
  cligCore::console::clear();
  int current = _current;
  std::cout << title << std::endl
            << "Please select a value between " << _lower << " and " << _upper << "." << std::endl
            << std::endl
            << " < " << current << " > \r" << std::flush;

  bool failsafe = false;
  while ( true ) {
    if ( not failsafe ) {
      cligCore::input::getKeyInput();
      failsafe = true;
    }
    switch ( cligCore::input::getKeyInput() ) {
    case cligCore::input::Keys::right: {
      if ( current < _upper ) current++;

      std::cout << " < " << current << " > \r" << std::flush;
      break;
    }
    case cligCore::input::Keys::left: {
      if ( current > _lower ) current--;

      std::cout << " < " << current << " > \r" << std::flush;
      break;
    }
    case cligCore::input::Keys::enter: {
      _current = current;
    }
    case cligCore::input::Keys::escape: {
      return;
    }
    }
  }
}
void cligCore::types::Range::showChooser( char title[] ) {
  std::string str( title );
  showChooser( str );
}
int cligCore::types::Range::getCurrent() { return _current; }