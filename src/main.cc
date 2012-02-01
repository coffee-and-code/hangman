#include <stdlib.h>
#include <stdio.h>

#include "game_state.hh"
#include "input.hh"

int MAX_PHRASE_LENGTH = 256;

int main(int argc, char *argv[]) {
	char *phrase = NULL;
	int ch;
	Input *input = new Input();

	phrase = (char *)malloc(sizeof(char) * MAX_PHRASE_LENGTH);

	printf("Enter the secret phrase:\n");
	fgets(phrase, MAX_PHRASE_LENGTH, stdin);
	printf("Your secret phrase is: %s", phrase);

	GameState *gameState = new GameState(phrase);

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

	free(phrase);
	return 0;
}
