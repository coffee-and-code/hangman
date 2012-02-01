#ifndef INPUT_CC
#define INPUT_CC

#include <stdio.h>

#include "input.hh"

Input::Input() {
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
