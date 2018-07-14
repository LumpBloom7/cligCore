#include "clig.hpp"
#include <conio.h>
cligCore::input::Keys cligCore::input::getKeyInput() {
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
  case '\r': return Keys::enter;
  }
}