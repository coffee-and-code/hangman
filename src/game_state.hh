#ifndef GAME_STATE_HH
#define GAME_STATE_HH

class GameState {
public:
	GameState(char *phrase);
	void guess(char ch);
	~GameState();
private:
	char *phrase;
	char *hidden_phrase;
	char guessed[26];
	int guessCount;

	void insertGuess(char ch);
	bool alreadyGuessed(char ch);
};

#endif
