#ifndef GAME_H
#define GAME_H

#include "Deck.h"

class Game {
private:
	Deck deck;
	Hand player;
	Hand dealer;
	
	enum {HIT, STAY, RESTART, QUIT, HELP};

	void printGreeting();
	void printHelp();
	void resetGame();
	int askPlayer();
public:
	Game();
	void play();

}

#endif