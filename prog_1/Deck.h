
#ifndef DECK_H
#define DECK_H
#include "Card.h"
// John Fahriddinov
// CECS 325-02
// Prog 1 - One Card War
// 09/18/25
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.


class Deck {
public:
	Deck();
	
	bool isEmpty();

	Card deal();
	
	void display();

	void shuffle();
private:
	int current_card_index;
	Card cards[52];
};

#endif
