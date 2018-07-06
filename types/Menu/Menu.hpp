#ifndef MENU_HPP
#define MENU_HPP

namespace cligCore {
  namespace types {
    class Menu {
    public:
      Menu( std::vector<std::string> &menuContent, std::string title = "Menu", int pointerLocation = 0 );
      int show();

    private:
      void _updateMenu();
      void _printMenu();
      std::string _title;
      std::vector<std::string> &_menuContent;
      int _pointerLocation = 0;
      cligCore::types::Range _visibleRange;
    };
  } // namespace types
} // namespace cligCore

#endif