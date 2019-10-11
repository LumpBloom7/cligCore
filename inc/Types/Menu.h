#pragma once
#include <vector>
#include <string>
#include "input.h"
#include "Range.h"


namespace cligCore::types {
	class Menu {
	public:
		Menu(const std::vector<std::string>& menuContent, const std::string& title, int pointerLocation = 0);
		int show();

	private:
		void _updateMenu();
		void _printMenu();
		const std::string _title;
		const std::vector<std::string> _menuContent;
		int _pointerLocation = 0;
		Range _visibleRange;
		int _maxLength = 0;

		std::string _cleanBuffer{};
	};
}