#ifndef GAME_STATE_CC
#define GAME_STATE_CC

#include <stdio.h>
#include <stdlib.h>

#include "game_state.hh"

GameState::GameState(char *phrase) {
	this->phrase = phrase;
}

void GameState::guess(char ch) {
	printf("You guessed: %c\n", ch);
}

GameState::~GameState() {
	free(this->phrase);
}

#endif
