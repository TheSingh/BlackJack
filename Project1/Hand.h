#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
private:
	std::vector<Card> cards;
public:
	void addCard(Card);		//add a new card to the hand
	bool isBust();			//Check to see if you've gone over 21
	int getValue();			//get the current value of your hand
	friend std::ostream& operator<<(std::ostream&, Hand);
};


#endif