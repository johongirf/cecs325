// John Fahriddinov
// CECS 325-02
// Prog 1 - One Card War
// 09/18/25
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <string>
#include <cstdlib>// use if rand doesn't alr exist.
#include "Deck.h"
#include "Card.h"
using namespace std;

Deck::Deck(){
    char suit[] = {'C', 'S', 'D', 'H'};
    char rank[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int index = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            cards[index++] = Card(rank[j], suit[i]);
        }
    }
    current_card_index = 0;
}

Card Deck::deal(){
    if(current_card_index < 52)
        return cards[current_card_index++];

    return Card();
}

void Deck::display(){
    int index = 0;
    for(int i = 0; i < 4; i++){
	    for(int j = 0; j < 12; j++){
	        cards[index++].display();
            cout << ',';
	    }
        cards[index++].display();
	    cout <<  endl;
    }
}
void Deck::shuffle(){
    srand(time(NULL));
    for(int i = 0; i < 500; i++){
        int x = rand()%52;
        int y = rand()%52;
        Card holder = cards[x];
        cards[x] = cards[y];
        cards[y] = holder;
    }
}

bool Deck::isEmpty(){
	return(0);
}
