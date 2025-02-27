#include "Card.h"
#include <string>

//default constructor creates a Joker card
Card::Card() {
	this->setSuit(JOKER); 
	this->setNumber(0);
}

Card::Card(int s, int num) {
	this->setSuit(s);
	this->setNumber(num);
}

//Accessors
int Card::getSuit() {
	return this->suit;
}

int Card::getNumber() {
	return this->number;
}

//Mutators
void Card::setSuit(int s) {
	this->suit = s;
}

void Card::setNumber(int num) {
	this->number = num;
}

//A helper function to convert the number to string
std::string getNameFomNumber(Card c) {
	int num = c.getNumber();
	std::string ret = "";

	if( (num > 1) && (num < 10) ) {
		ret = std::to_string(num);
	} else {
		switch(num) {
		case 10 :
			ret = "Jack";
			break;
		case 11 :
			ret = "Queen";
			break;
		case 12 : 
			ret = "King";
			break;
		case 1 :
			ret = "Ace";
			break;
		}
	}

	return ret;
}

//A helper function to convert the suit to string
std::string getNameFromSuit(Card c) {
	int s = c.getSuit();
	std::string ret = "";

	switch(s) {
	case HEARTS :
		ret = "Hearts";
		break;
	case SPADES :
		ret = "Spades";
		break;
	case CLUBS :
		ret = "Clubs";
		break;
	case DIAMONDS :
		ret = "Diamonds";
		break;
	}

	return ret;
}

//overwrite right shift operator for cout
std::ostream& operator<< (std::ostream& strm, Card& c) {
	if(c.getNumber() == 0)
		strm << "Joker";
	else {
		strm << getNameFomNumber(c) << " of " << getNameFromSuit(c);
	}

	return strm;
}