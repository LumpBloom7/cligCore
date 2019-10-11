#pragma once
#include <string>
#include "input.h"
#include "console.h"
namespace cligCore::types {
	class Range {
	public:
		Range(int lowerBounds, int upperBounds, bool isSelectable = false);
		Range(int lowerBounds, int upperBounds, int currentVal);
		Range();
		int getLower();
		int getUpper();
		void setLower(int value);
		void setUpper(int value);
		void shift(int value);
		void showChooser(const std::string& title);
		int getCurrent();

	private:
		int _current;
		int _lower, _upper;
		bool _isSelectable = false;
	};
}