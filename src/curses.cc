#ifndef CURSES_CC
#define CURSES_CC

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>

#include "curses.hh"

Curses::Curses() {
	if ((this->window = initscr()) == NULL) {
		fprintf(stderr, "Error initializing ncurses.\n");
		exit(EXIT_FAILURE);
	}
}

void Curses::putPrompt(const char *prompt) {
	mvaddstr(13, 33, prompt);
	refresh();
	sleep(3);
}

void Curses::putPhrase(const char *phrase) {
}

void Curses::putGuesses(char *guesses, int count) {
}

char *Curses::getString() {
	char *string;
	return string;
}

char Curses::getChar() {
	char ch;
	return ch;
}

Curses::~Curses() {
	delwin(this->window);
	endwin();
	refresh();
}

#endif
