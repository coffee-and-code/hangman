#ifndef IO_CC
#define IO_CC

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>

#include "io.hh"

IO::IO() {
	this->MAX_STRING_LENGTH = 256;
}

void IO::putPrompt(const char *prompt) {
}

void IO::putPhrase(const char *phrase) {
}

void IO::putGuesses(char *guessed, int count) {
}

char IO::getChar() {
	return '\0';
}

char *IO::getString() {
	return NULL;
}

void IO::cleanString(char *s) {
	while (*s && *s != '\n' && *s != '\r') s++;
	*s = 0;
}

IO::~IO() {}

#endif
