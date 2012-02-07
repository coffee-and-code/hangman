#ifndef TERMINAL_HH
#define TERMINAL_HH

#include "io.hh"

class Terminal: public IO {
public:

	// output functions
	void putPrompt(const char *prompt);
	void putPhrase(const char *phrase);
	void putGuesses(char *guessed, int count);

	// input functions
	char getChar();
	char *getString();
};

#endif
