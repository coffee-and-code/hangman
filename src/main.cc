#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "game_state.hh"

int main(int argc, char *argv[]) {
	GameState *gameState = new GameState();

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
