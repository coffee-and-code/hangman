#ifndef GAME_STATE_HH
#define GAME_STATE_HH

#include "io.hh"

class GameState {
public:
	GameState(Mode mode);
	void print();
	~GameState();
private:
	IO *io;
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
