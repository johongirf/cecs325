// John Fahriddinov
// CECS 325-02
// Prog 1 - One Card War
// 09/18/25
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include "Card.h"
using namespace std;
class Card
{
public:
    Card::Card(){
        rank = ' ';
        suit = ' ';
    }

    Card::Card(char r, char s){
        rank = r;
        suit = s;
    }

    void Card::display(){
        cout << rank << suit; 
    }

    int Card::compare(Card c){
        int rankIndex = -1;
        int opponentIndex = -1;
        char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
        for(int i = 0; i < sizeof(ranks); i++){
            if(rank == ranks[i])
                rankIndex = i;
            if(c.rank == ranks[i])
                opponentIndex = i;
        }
        if(rankIndex > opponentIndex)
            return 1;
        else if(rankIndex < opponentIndex)
            return -1;
        else
            return 0;
    }
private:
    char rank;
    char suit;
}