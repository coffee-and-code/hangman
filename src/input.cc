#ifndef INPUT_CC
#define INPUT_CC

#include <stdio.h>
#include <stdlib.h>

#include "input.hh"

int MAX_STRING_LENGTH = 256;

Input::Input() {
}

char *Input::getString() {
	char *string = NULL;

	string = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);
	fgets(string, MAX_STRING_LENGTH, stdin);

	return string;
}

char Input::getChar() {
	char ch, dummy;

	ch = getchar();

	while ((dummy = getchar()) != '\n') {}

	return ch;
}

Input::~Input() {
}

#endif
