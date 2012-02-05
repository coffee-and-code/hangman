#ifndef IO_CC
#define IO_CC

#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

#include "io.hh"

int MAX_STRING_LENGTH = 256;

IO::IO(Mode mode) {
	this->mode = mode;

	switch (this->mode) {
		case curses:
			if ((this->window = initscr()) == NULL) {
				fprintf(stderr, "Error initializing ncurses.\n");
				exit(EXIT_FAILURE);
			}

			break;

		case terminal:
			break;

		default:
			break;
	}
}

void IO::putPrompt(const char *prompt) {
	switch (this->mode) {
		case curses:
			this->putPromptCurses(prompt);
			break;
		
		case terminal:
			this->putPromptTerminal(prompt);
			break;

		default:
			break;
	}
}

void IO::putPhrase(const char *phrase) {
	switch (this->mode) {
		case curses:
			this->putPromptCurses(phrase);
			break;
		
		case terminal:
			this->putPromptTerminal(phrase);
			break;

		default:
			break;
	}
}

void IO::putGuesses(char *guesses, int count) {
	switch (this->mode) {
		case curses:
			this->putGuessesCurses(guesses, count);
			break;
		
		case terminal:
			this->putGuessesTerminal(guesses, count);
			break;

		default:
			break;
	}
}

char *IO::getString() {
	char *string;

	switch (this->mode) {
		case curses:
			string = this->getStringCurses();
			break;
		
		case terminal:
			string = this->getStringTerminal();
			break;

		default:
			break;
	}

	return string;
}

char IO::getChar() {
	char ch;

	switch (this->mode) {
		case curses:
			ch =  this->getCharCurses();
			break;
		
		case terminal:
			ch =  this->getCharTerminal();
			break;

		default:
			break;
	}

	return ch;
}

void IO::putPromptTerminal(const char *prompt) {
	printf("%s\n", prompt);
}

void IO::putPhraseTerminal(const char *phrase) {
	printf("%s\n", phrase);
}

void IO::putGuessesTerminal(char *guesses, int count) {
	for (int i = 0; i < count; i++) {
		printf("%c", guesses[i]);
		
		if (i < count - 1) {
			printf(", ");
		}
	}

	printf("\n");
}

void IO::putPromptCurses(const char *prompt) {}
void IO::putPhraseCurses(const char *phrase) {}
void IO::putGuessesCurses(char *guessed, int count) {}

char IO::getCharTerminal() {
	char ch, dummy;

	ch = getchar();

	while ((dummy = getchar()) != '\n') {}

	return ch;
}

char *IO::getStringTerminal() {
	char *string = NULL;

	string = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);
	fgets(string, MAX_STRING_LENGTH, stdin);
	this->cleanString(string);

	return string;
}

char IO::getCharCurses() {
	char ch;
	return ch;
}

char *IO::getStringCurses() {
	char *string;
	return string;
}

void IO::cleanString(char *s) {
	while (*s && *s != '\n' && *s != '\r') s++;
	*s = 0;
}

IO::~IO() {
	free(this->window);
}

#endif
