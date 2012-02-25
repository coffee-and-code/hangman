#ifndef CURSES_HH
#define CURSES_HH

#include <curses.h>

#include "io.hh"

class Curses: public IO {
public:
	Curses();

	// utilities
	void clearScreen();
	void test();

	// output functions
	void putPrompt(const char *prompt);
	void putPhrase(const char *phrase);
	void putGuesses(char *guessed, int count);

	// input functions
	char getChar();
	char *getString();

	~Curses();
private:
	WINDOW *window;
	int col;
	int row;
};

#endif
