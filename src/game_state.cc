#ifndef GAME_STATE_CC
#define GAME_STATE_CC

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "game_state.hh"

GameState::GameState(char *phrase) {
	this->hidden_phrase = (char *)malloc(sizeof(char) * strlen(phrase));
	this->phrase = phrase;
	char *hidden_phrase = this->hidden_phrase;

	for (char *cur = phrase; *cur != '\0'; cur++) {
		*hidden_phrase = (*cur == ' ') ? ' ' : '_';

		hidden_phrase++;
	}

	printf("%s\n", this->hidden_phrase);
}

void GameState::guess(char ch) {
	printf("You guessed: %c\n", ch);
}

GameState::~GameState() {
	free(this->phrase);
	free(this->hidden_phrase);
}

#endif
