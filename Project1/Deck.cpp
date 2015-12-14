#include "Deck.h"
#include <algorithm>
#include <ctime>



//populates the deck with 52 unique cards, unshuffled
Deck::Deck() {
	//for each suit
	for(int i=HEARTS; i<=DIAMONDS; ++i) {
		//for each number within the suit
		for(int j=1; j<13; ++j) {
			this->cards.push_back(Card(i, j));
		}
	}

	srand(time(NULL));
}

//Deals a single card and removes it from the deck
void Deck::deal(Hand &h) {
	h.addCard(this->cards.back());
	this->cards.pop_back();
}

void Deck::reset() {
	this->cards.clear();

	//refill the deck
	for(int i=HEARTS; i<=DIAMONDS; ++i) {
		for(int j=1; j<13; ++j) {
			this->cards.push_back(Card(i, j));
		}
	}

	//srand(time(NULL));
}

//Function passed into random_shuffle
int _shuffle(int i) {
	return std::rand()%i;
}

//shuffles the card using the ctime to randomize it
void Deck::shuffle() {
	random_shuffle(this->cards.begin(), this->cards.end(), _shuffle);
}

