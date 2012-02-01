#ifndef GAME_STATE_HH
#define GAME_STATE_HH

class GameState {
public:
	GameState();
	void guess(char ch);
	~GameState();
private:
	char *phrase;
};

#endif
