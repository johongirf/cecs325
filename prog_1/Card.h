



#ifndef CARD_H
#define CARD_H
// John Fahriddinov
// CECS 325-02
// Prog 1 - One Card War
// 09/18/25
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

class Card
{
public:
	Card(char, char);
	Card();
	void display();
	int compare(Card);
private:
	char suit;
	char rank;
};

#endif




