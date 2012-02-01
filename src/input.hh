#ifndef INPUT_HH
#define INPUT_HH

class Input {
public:
	Input();
	char getChar();
	char *getString();
	~Input();

private:
	void cleanString(char *string);
};

#endif
