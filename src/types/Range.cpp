#include "Types/Range.h"

namespace cligCore::types {
	Range::Range() : _lower(0), _upper(10), _current(0), _isSelectable(false) {}
	Range::Range(int lowerBounds, int upperBounds, bool isSelectable) {
		// Differentiate the smaller value from the bigger value to ease processing and to avoid any potential bugs.
		_lower = (lowerBounds <= upperBounds) ? lowerBounds : upperBounds;
		_upper = (lowerBounds <= upperBounds) ? upperBounds : lowerBounds;
		_isSelectable = isSelectable;
		_current = _lower;
	}
	Range::Range(int lowerBounds, int upperBounds, int currentVal) {
		// Differentiate the smaller value from the bigger value to ease processing and to avoid any potential bugs.
		_lower = (lowerBounds <= upperBounds) ? lowerBounds : upperBounds;
		_upper = (lowerBounds <= upperBounds) ? upperBounds : lowerBounds;
		_isSelectable = true;
		_current = (currentVal >= _lower && currentVal <= _upper) ? currentVal : _lower;
	}
	int Range::getLower() { return _lower; }
	int Range::getUpper() { return _upper; }

	void Range::setLower(int value) { _lower = value; }
	void Range::setUpper(int value) { _upper = value; }

	void Range::shift(int value) {
		_lower += value;
		_upper += value;
	}

	void cligCore::types::Range::showChooser(const std::string& title) {
		cligCore::console::clear();
		int current = _current;
		std::cout << rang::style::underline << title << rang::style::reset << "\n"
			<< "Please select a value between " << _lower << " and " << _upper << "." << std::endl
			<< std::endl
			<< (current == _lower ? "   " : " < ") << current << (current == _upper ? "   " : " > ") << "                 \r" << std::flush;

		bool failsafe = false;
		while (true) {
			if (!failsafe) {
				cligCore::input::getKeyInput();
				failsafe = true;
			}
			switch (cligCore::input::getKeyInput()) {
			case cligCore::input::Keys::Right: {
				if (current < _upper) current++;

				std::cout << (current == _lower ? "   " : " < ") << current << (current == _upper ? "   " : " > ") << "                 \r" << std::flush;
				break;
			}
			case cligCore::input::Keys::Left: {
				if (current > _lower) current--;

				std::cout << (current == _lower ? "   " : " < ") << current << (current == _upper ? "   " : " > ") << "                 \r" << std::flush;
				break;
			}
			case cligCore::input::Keys::Enter: {
				_current = current;
			}
			case cligCore::input::Keys::Escape: {
				return;
			}
			}
		}
	}
	int Range::getCurrent() { return _current; }
}