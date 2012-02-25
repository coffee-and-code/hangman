#ifndef IO_HH
#define IO_HH

class IO {
public:
	IO();

	// utilities
	virtual void clearScreen();
	virtual void test();

	// output functions
	virtual void printGallows(int state);
	virtual void putPrompt(const char *prompt);
	virtual void putPhrase(const char *phrase);
	virtual void putGuesses(char *guessed, int count);

	// input functions
	virtual char getChar();
	virtual char *getString();

	virtual ~IO();
protected:
	int MAX_STRING_LENGTH;

	void cleanString(char *string);
};

#endif
