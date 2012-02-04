#ifndef GAME_STATE_CC
#define GAME_STATE_CC

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "game_state.hh"

GameState::GameState(char *phrase) {
	this->guessCount = 0;
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
	if (isalpha(ch) && !this->alreadyGuessed(ch)) {
		this->insertGuess(ch);
	}

	for (int i = 0; i < this->guessCount; i++) {
		printf("%c, ", this->guessed[i]);
	}

	printf("\n");
}

void GameState::insertGuess(char ch) {
	for (int i = this->guessCount; i >= 0; i--) {
		if (ch > this->guessed[i - 1] || i == 0) {
			this->guessed[i] = ch;
			break;
		} else {
			this->guessed[i] = this->guessed[i - 1];
		}
	}

	this->guessCount++;
}

bool GameState::alreadyGuessed(char ch) {
	for (int i = 0; i < this->guessCount; i++) {
		if (this->guessed[i] == ch) {
			return true;
		}
	}

	return false;
}

GameState::~GameState() {
	free(this->phrase);
	free(this->hidden_phrase);
	free(this->guessed);
}

#endif
