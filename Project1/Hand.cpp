#include "Hand.h"

//pushes a new card into the list of cards in your hand
void Hand::addCard(Card c) {
	this->cards.push_back(c);
}

//returns the total value of your hand right now
int Hand::getValue() {
	int value = 0;
	int aceCount = 0;	//special case

	//Systematically add each card to the total
	for(Card c : this->cards) {
		if (c.getNumber() != 1) {
			//Card is not an Ace
			if(c.getNumber() > 9) {
				//Jack, Queen, King = 10
				value += 10;
			} else {
				value += c.getNumber();
			}
		} else {
			//account for aces afterwards
			++aceCount;
		}
	}

	while(aceCount > 1) {
		//If there's two aces, at least one of them must be counted as one
		//or you go over 21
		++value;
		--aceCount;
	}

	//if there is one single Ace unaccounted for in the total
	if(aceCount) {
		if( (value+11) <= 21)
			value += 11;
		else
			++value;
	}
	return value;
}

//if value > 21 then you've bust
bool Hand::isBust() {
	if (this->getValue() > 21)
		return true;
	else
		return false;
}

//prints the Hand to the given stream
std::ostream& operator<<(std::ostream& strm, Hand h) {
	strm << "Cards in hand: \n";

	//systematically print out the cards in hand
	if(h.cards.size() > 0) {
		for(Card c : h.cards) {
			strm << "\t" << c << std::endl;
		}
	} else {
		strm << "\t" << "Your hand is empty.\n";
	}

	return strm;
}
