#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

	printf("Guess a letter: ");
	while ((ch = getchar()) != EOF) {
		ch = input->getChar();
		gameState->guess(ch);
		printf("Guess a letter: ");
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
