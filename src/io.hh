#ifndef IO_HH
#define IO_HH

class IO {
public:
	IO();

	// output functions
	virtual void putPrompt(const char *prompt);
	virtual void putPhrase(const char *phrase);
	virtual void putGuesses(char *guessed, int count);

	// input functions
	virtual char getChar();
	virtual char *getString();

	~IO();
protected:
	int MAX_STRING_LENGTH;

	void cleanString(char *string);
};

#endif
