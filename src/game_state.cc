#ifndef GAME_STATE_CC
#define GAME_STATE_CC

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "game_state.hh"
#include "io.hh"

GameState::GameState(Mode mode) {
	this->guessCount = 0;
	this->io = new IO(mode);

	this->init();
}

void GameState::guess(char ch) {
	if (isalpha(ch) && !this->alreadyGuessed(ch)) {
		this->insertGuess(ch);
		this->updatePhrase();
	}
}


void GameState::print() {
	this->io->putGuesses(this->guessed, this->guessCount);
	this->io->putPhrase(this->currentPhrase);
	this->io->putPrompt("Guess a letter: ");
	this->guess(this->io->getChar());
}

/****
 * PRIVATE FUNCTIONS
 */

void GameState::init() {
	this->io->putPrompt("Enter the secret phrase:");

	this->phrase = this->io->getString();
	this->currentPhrase = (char *)malloc(sizeof(char) * strlen(this->phrase));
	this->updatePhrase();

	this->print();
}

void GameState::updatePhrase() {
	char *currentPhrase = this->currentPhrase;

	for (char *cur = this->phrase; *cur != '\0'; cur++) {
		*currentPhrase = (this->alreadyGuessed(*cur)) ? *cur : '_';
		currentPhrase++;
	}
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
	free(this->currentPhrase);
	free(this->guessed);
	free(this->io);
}

#endif
