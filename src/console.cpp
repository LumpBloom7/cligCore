#include "console.h"
namespace cligCore::console {
	int getConsoleWidth() {
#if defined( _WIN32 ) || defined( _WIN64 )
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int columns;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		return columns;

#elif defined( __unix__ ) || defined( __unix )
		struct winsize max;
		ioctl(0, TIOCGWINSZ, &max);
		return max.ws_col;
#endif
	}

	int getConsoleHeight() {
#if defined( _WIN32 ) || defined( _WIN64 )
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int rows;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
		return rows;

#elif defined( __unix__ ) || defined( __unix )
		struct winsize max;
		ioctl(0, TIOCGWINSZ, &max);
		return max.ws.col
#endif
	}

	std::string getPassword(const std::string& prompt) {
#if defined( _WIN32 ) || defined( _WIN64 )
		std::cout << prompt << std::flush;
		std::string password;
		toggleEcho(false);
		std::cin >> password;

		toggleEcho(true);
		return password;

#elif defined( __unix__ ) || defined( __unix )
		std::string password = getpass(prompt);
		return password;

		(void)tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
	}

	void clear() {
#if defined( _WIN32 ) || defined( _WIN64 )
		COORD topLeft{ 0, 0 };
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO screen;
		DWORD written;
		GetConsoleScreenBufferInfo(console, &screen);
		FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
		FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
			screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
		SetConsoleCursorPosition(console, topLeft);
		std::cout << rang::style::reset;

#elif defined( __unix__ ) || defined( __unix )
		std::cout << "\x1B[2J\x1B[H";
		std::cout << style::reset;
#endif
	}

	void toggleEcho(const bool& enable) // Stops the console from printing anything if disabled.
	{
#if defined( _WIN32 ) || defined( _WIN64 )
		HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
		DWORD mode;
		GetConsoleMode(hStdin, &mode);

		if (!enable) {
			mode &= ~ENABLE_ECHO_INPUT;
		}
		else {
			mode |= ENABLE_ECHO_INPUT;
		}

		SetConsoleMode(hStdin, mode);

#elif defined( __unix__ ) || defined( __unix )
		struct termios tty;
		tcgetattr(STDIN_FILENO, &tty);
		if (not enable) {
			tty.c_lflag &= ~ECHO;
		}
		else {
			tty.c_lflag |= ECHO;
		}

		(void)tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
	}

	void moveCursor(int x, int y) {
		COORD topLeft{ x, y };
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(console, topLeft);
	}
}