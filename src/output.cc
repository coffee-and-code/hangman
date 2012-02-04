#ifndef OUTPUT_CC
#define OUTPUT_CC

#include <stdio.h>
#include <curses.h>

#include "output.hh"

Output::Output() {
	if ((this->window = initscr()) == NULL) {
		fprintf(stderr, "Error initializing ncurses.\n");
	}
}

void Output::prompt(const char *prompt) {
	printf("%s\n", prompt);
}

void Output::phrase(const char *phrase) {
	printf("%s\n", phrase);
}

void Output::guesses(char *guesses, int count) {
	for (int i = 0; i < count; i++) {
		printf("%c, ", guesses[i]);
	}

	printf("\n");
}

Output::~Output() {
}

#endif
