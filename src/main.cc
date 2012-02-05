#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "game_state.hh"

int main(int argc, char *argv[]) {
	enum Mode mode = terminal;

	if (argc > 1 && strcmp(argv[1], "curses") == 0) {
		mode = curses;
	}

	GameState *gameState = new GameState(mode);

	while (true) {
		gameState->print();
	}


	// get secret phrase
	// clear screen
	// game loop
	// 	print game state
	// 	get char (take first char, then discard next chars until a newline is found)
	// 	submit guess
	// end loop

	return 0;
}
