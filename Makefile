CC = g++
CFLAGS = -Wall -c -g
LDFLAGS = 
SRC = ./src
SOURCES = $(SRC)/input.cc $(SRC)/game_state.cc $(SRC)/main.cc
OBJECTS = $(SOURCES:.cc=.o)
BIN = hangman

all: $(SOURCES) $(BIN)

$(BIN): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(BIN)
