#ifndef OUTPUT_HH
#define OUTPUT_HH

#include <curses.h>

class Output {
public:
	Output();
	void prompt(const char *prompt);
	void phrase(const char *phrase);
	void guesses(char *guessed, int count);
	~Output();
private:
	WINDOW *window;
};

#endif
