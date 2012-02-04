#ifndef GAME_STATE_HH
#define GAME_STATE_HH

#include "output.hh"
#include "input.hh"

class GameState {
public:
	GameState();
	void print();
	~GameState();
private:
	Output *output;
	Input *input;
	char *phrase;
	char *currentPhrase;
	char guessed[26];
	int guessCount;

	void init();
	void guess(char ch);
	void printPhrase();
	void updatePhrase();
	void insertGuess(char ch);
	bool alreadyGuessed(char ch);
};

#endif
