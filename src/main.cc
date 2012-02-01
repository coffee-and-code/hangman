#include <stdlib.h>
#include <stdio.h>

#include "game_state.hh"
#include "input.hh"

int main(int argc, char *argv[]) {
	int ch;
	Input *input = new Input();
	GameState *gameState = new GameState();

	while (true) {
		printf("Guess a letter: ");
		ch = input->getChar();
		gameState->guess(ch);
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
