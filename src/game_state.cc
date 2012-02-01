#ifndef GAME_STATE_CC
#define GAME_STATE_CC

#include <stdio.h>
#include <stdlib.h>

#include "game_state.hh"

int MAX_PHRASE_LENGTH = 256;

GameState::GameState() {
	char *phrase = NULL;

	phrase = (char *)malloc(sizeof(char) * MAX_PHRASE_LENGTH);
	printf("Enter the secret phrase:\n");
	fgets(phrase, MAX_PHRASE_LENGTH, stdin);

	this->phrase = phrase;
}

void GameState::guess(char ch) {
	printf("You guessed: %c\n", ch);
}

GameState::~GameState() {
	free(this->phrase);
}

#endif
