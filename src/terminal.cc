#ifndef TERMINAL_CC
#define TERMINAL_CC

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>

#include "terminal.hh"

void Terminal::clearScreen() {}

void Terminal::test() {
	this->putPrompt("Enter a message: ");
	char *str = this->getString();
	this->putPhrase("you said:");
	this->putPhrase(str);
}

void Terminal::printGallows(int state) {
	switch (state) {
		case 0:
			printf("+---+---\n");
			printf("|   |	\n");
			printf("|   	\n");
			printf("|   	\n");
			printf("|   	\n");
			printf("+-------\n");
			break;
		
		case 1:
			printf("+---+---\n");
			printf("|   |	\n");
			printf("|   0	\n");
			printf("|   	\n");
			printf("|   	\n");
			printf("+-------\n");
			break;

		case 2:
			printf("+---+---\n");
			printf("|   |	\n");
			printf("|   0	\n");
			printf("|   |	\n");
			printf("|   	\n");
			printf("+-------\n");
			break;
		
		case 3:
			printf("+---+---\n");
			printf("|   |	\n");
			printf("|   0	\n");
			printf("|  /|	\n");
			printf("|   	\n");
			printf("+-------\n");
			break;
		
		case 4:
			printf("+---+---\n");
			printf("|   |	\n");
			printf("|   0	\n");
			printf("|  /|\\	\n");
			printf("|   	\n");
			printf("+-------\n");
			break;
		
		case 5:
			printf("+---+---\n");
			printf("|   |	\n");
			printf("|   0	\n");
			printf("|  /|\\	\n");
			printf("|  / 	\n");
			printf("+-------\n");
			break;

		case 6:
			printf("+---+---\n");
			printf("|   |	\n");
			printf("|   0	\n");
			printf("|  /|\\	\n");
			printf("|  / \\	\n");
			printf("+-------\n");
			break;
	}
}

void Terminal::putPrompt(const char *prompt) {
	printf("%s\n", prompt);
}

void Terminal::putPhrase(const char *phrase) {
	printf("%s\n", phrase);
}

void Terminal::putGuesses(char *guesses, int count) {
	for (int i = 0; i < count; i++) {
		printf("%c", guesses[i]);
		
		if (i < count - 1) {
			printf(", ");
		}
	}

	printf("\n");
}

char Terminal::getChar() {
	char ch, dummy;

	ch = getchar();

	while ((dummy = getchar()) != '\n') {}

	return ch;
}

char *Terminal::getString() {
	char *string = NULL;

	string = (char *)malloc(sizeof(char) * this->MAX_STRING_LENGTH);
	fgets(string, this->MAX_STRING_LENGTH, stdin);
	this->cleanString(string);

	return string;
}

#endif
