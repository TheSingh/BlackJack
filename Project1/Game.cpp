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

//Asks the player for their choice
int Game::askPlayer() {
	//clear buffer

	std::cout << this->player;
	std::cout << "What will you do?\n";

	char cmd = getchar();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');


	//parse the input and return the correct code
	switch(cmd) {
	case 'h' : 
		return HIT;
		break;
	case 's' :
		return STAY;
		break;
	case 'r' :
		return RESTART;
		break;
	case 'q' :
		return QUIT;
		break;
	case '?' :
		return HELP;
		break;
	default :
		std::cout << "Command not recognized, please try again.\n";
		return 0;
		break;
	}
}

void Game::dealerTurn() {

}

void Game::resetGame() {

}

int playerBust() {
	std::cout << "Darn! You've lost!\n";
	std::cout << "Press [q] to quit, any other key to restart.\n";

	char cmd;
	std::cin >> cmd;

	if(cmd == 'q') return 1;

	return 0;
}

void Game::play() {
	for(;;) {
		int choice = askPlayer();
		//handle each user choice
		switch(choice) {
		case HIT :
			std::cout << "You chose hit on " << player.getValue() << std::endl;
			deck.deal(player);
			if(player.isBust()) {
				std::cout << player;
				//user is over the 21 limit
				if(playerBust()) {
					//user chooses to quit
					std::cout << "Thank you for playing.\n";
					exit(0);
				} else {
					resetGame();
				}
			}
			break;
		case STAY :
			std::cout << "You chose to stay on: " << player.getValue() << std::endl;
			dealerTurn();
			break;
		case RESTART:
			std::cout << "Restarting game...\n";
			resetGame();
			break;
		case QUIT :
			std::cout << "Thank you for playing.\n";
			exit(0);
			break;
		case HELP : 
			printHelp();
			break;
		}
		std::cout << std::endl;

	}
}