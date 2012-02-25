#ifndef CURSES_CC
#define CURSES_CC

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <curses.h>

#include "curses.hh"

Curses::Curses() {
	if ((this->window = initscr()) == NULL) {
		fprintf(stderr, "Error initializing ncurses.\n");
		exit(EXIT_FAILURE);
	}

	getmaxyx(stdscr, this->row, this->col);
}

void Curses::test() {
	this->clearScreen();
	this->putPrompt("Enter a message:");
	char *str = this->getString();
	this->putPhrase("you said:");
	this->putPhrase(str);
	this->getChar();
}

void Curses::clearScreen() {
	clear();
}

void Curses::putPrompt(const char *prompt) {
	mvprintw(this->row/2, (col-strlen(prompt))/2, "%s", prompt);
}

void Curses::putPhrase(const char *phrase) {
	mvprintw(LINES - 2, 0, "%s", phrase);
}

void Curses::putGuesses(char *guesses, int count) {
}

char *Curses::getString() {
	char *str = (char *)malloc(sizeof(char) * 80);

	getstr(str);

	return str;
}

char Curses::getChar() {
	return getch();
}

Curses::~Curses() {
	delwin(this->window);
	endwin();
	refresh();
}

#endif
