#include "Menu.hpp"

cligCore::types::Menu::Menu( std::vector<std::string> &menuContent, std::string title, int pointerLocation )
    : _menuContent( menuContent ), _title( title ), _pointerLocation( pointerLocation ) {
  _updateMenu();
}
int cligCore::types::Menu::show() {
#if defined( _WIN32 ) || defined( _WIN64 )
  int numberOfOptions = _menuContent.size() - 1;
  _printMenu();
  bool failcheck{};
  while ( true ) {
    if ( not failcheck ) {
      cligCore::input::getKeyInput();
      failcheck = true;
    }
    switch ( cligCore::input::getKeyInput() ) {
    case cligCore::input::Keys::up: {
      _pointerLocation--;
      if ( _pointerLocation < 0 ) { _pointerLocation = numberOfOptions; }
      _printMenu();
      break;
    }
    case cligCore::input::Keys::down: {
      _pointerLocation++;
      if ( _pointerLocation > numberOfOptions ) { _pointerLocation = 0; }
      _printMenu();
      break;
    }
    case cligCore::input::Keys::enter: {
      std::string discard;
      std::getline( std::cin, discard );
      return _pointerLocation;
    }
    case cligCore::input::Keys::escape: {
      // if ( backEnabled ) { return -1; }break;
    }
    }
  }
  return -1;
#elif defined( __unix__ ) || defined( __unix )
  int numberOfOptions = _menuContent.size() - 1, _pointerLocation = 0;
  _printMenu();
  bool failcheck{};
  while ( true ) {
    switch ( cligCore::input::getArrowInput() ) {
    case cligCore::input::Keys::up: {
      if ( _pointerLocation < 0 ) { _pointerLocation = numberOfOptions; }
      _pointerLocation--;
      _printMenu();
      break;
    }
    case cligCore::input::Keys::down: {
      _pointerLocation++;
      if ( _pointerLocation > numberOfOptions ) { _pointerLocation = 0; }
      _printMenu();
      break;
    }
    case cligCore::input::Keys::enter: {
      return _pointerLocation;
    }
    case cligCore::input::Keys::escape: {
      if ( backEnabled ) { return -1 };
    }
    }
  }
  return -1;
#endif
}

void cligCore::types::Menu::_updateMenu() {
  int windowHeight = cligCore::console::getConsoleHeight() - 1;
  int halfHeight = windowHeight / 2;
  if ( _menuContent.size() > windowHeight )
    _visibleRange = cligCore::types::Range( 0, windowHeight );
  else
    _visibleRange = cligCore::types::Range( 0, _menuContent.size() );

  if ( _pointerLocation > halfHeight && _visibleRange.getUpper() < _menuContent.size() ) {
    int shiftAmount = _pointerLocation - halfHeight;
    int availableShifts = _menuContent.size() - _visibleRange.getUpper();
    if ( shiftAmount > availableShifts ) shiftAmount = availableShifts;
    _visibleRange.shift( shiftAmount );
  }
  if ( _visibleRange.getUpper() < _menuContent.size() ) _visibleRange.setUpper( _visibleRange.getUpper() - 1 );
  if ( _visibleRange.getLower() > 0 ) _visibleRange.setLower( _visibleRange.getLower() + 1 );
}

void cligCore::types::Menu::_printMenu() {
  _updateMenu();
  cligCore::console::clear();
  std::cout << termcolor::underline << _title << termcolor::reset << std::endl;
  int windowHeight = cligCore::console::getConsoleHeight();
  if ( _visibleRange.getLower() > 0 )
    std::cout << termcolor::magenta << "[ MORE ABOVE ]" << std::endl << termcolor::reset;
  for ( int i = _visibleRange.getLower(); i < _visibleRange.getUpper(); i++ ) {
    if ( _pointerLocation == i ) std::cout << termcolor::green << std::flush;
    std::cout << _menuContent[ i ] << std::flush;
    if ( i < _visibleRange.getUpper() - 1 ) std::cout << std::endl;
    std::cout << termcolor::reset << std::flush;
  }
  if ( _visibleRange.getUpper() < _menuContent.size() )
    std::cout << std::endl << termcolor::magenta << "[ MORE BELOW ]" << std::flush;
};