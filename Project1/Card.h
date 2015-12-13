#ifndef CARD_H
#define CARD_H

#include <iostream>

//provide readability for the suits, without having ot use strings.
enum suits {JOKER, HEARTS, SPADES, CLUBS, DIAMONDS};

//This will represent a card in a deck
class Card {
private:
	int suit;			//suit of the card
	int number;			//the number of the card
public:
	Card();				//default constructor
	Card(int, int);		
	int getSuit();		//accessors
	int getNumber();
	void setSuit(int);	//mutators
	void setNumber(int);
	friend std::ostream& operator<<(std::ostream&, Card&);
};

#endif