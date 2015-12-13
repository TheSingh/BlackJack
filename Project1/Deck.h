#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"
#include "Hand.h"

class Deck {
private:
	std::vector<Card> cards;
public:
	Deck();
	void shuffle();
	void reset();
	void deal(Hand&);
};

#endif