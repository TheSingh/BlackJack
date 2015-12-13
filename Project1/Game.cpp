#include "Game.h"


Game::Game() {
	this->deck.shuffle();

	//hand out two cards to each player
	this->deck.deal(this->player);
	this->deck.deal(this->dealer);
	this->deck.deal(this->player);
	this->deck.deal(this->dealer);

	//print the directions
	this->printGreeting();
	this->printHelp();
}

//simply prints the greeting
void Game::printGreeting() {
	std::cout << "Hello, and welcome to Robin's BlackJack!\n";
	std::cout << "A quick and simple BlackJack simulator.\n";
}

//prints the directions
void Game::printHelp() {
	std::cout << "Here are the possible commands: \n";
	std::cout << "\tPress [h] to hit.\n";
	std::cout << "\tPress [s] to stay.\n";
	std::cout << "\tPress [r] to restart.\n";
	std::cout << "\tPress [q] to quit.\n";
	std::cout << "\tPress [?] to get help.\n";
}

int Game::askPlayer() {
	std::cin.ignore(INT_MAX);

	std::cout << this->player;
	std::cout << "What will you do?\n";

	char cmd;
	std::cin >> cmd;

	switch(cmd) {
	case 'h' : 
		deck.deal(player);
		return HIT;
		break;
	case 's' :
		return STAY;
		break;
	case 'r' :
		resetGame();
		return RESTART;
		break;
	case 'q' :
		return QUIT;
	}
}

void Game::play() {
	for(;;) {
		int choice = askPlayer();
		if (choice == HIT) {

		}
	}
}