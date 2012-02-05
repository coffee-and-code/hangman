#ifndef IO_HH
#define IO_HH

#include <curses.h>

enum Mode {
	terminal,
	curses
};

class IO {
public:
	IO(Mode mode);

	// output functions
	void putPrompt(const char *prompt);
	void putPhrase(const char *phrase);
	void putGuesses(char *guessed, int count);

	// input functions
	char getChar();
	char *getString();

	~IO();
private:
	WINDOW *window;
	enum Mode mode;

	void putPromptTerminal(const char *prompt);
	void putPhraseTerminal(const char *phrase);
	void putGuessesTerminal(char *guessed, int count);

	void putPromptCurses(const char *prompt);
	void putPhraseCurses(const char *phrase);
	void putGuessesCurses(char *guessed, int count);

	char getCharTerminal();
	char *getStringTerminal();

	char getCharCurses();
	char *getStringCurses();

	void cleanString(char *string);
};

#endif
