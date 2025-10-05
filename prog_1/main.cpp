// John Fahriddinov
// CECS 325-02
// Prog 1 - One Card War
// 09/18/25
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;
 

int main(){
    Deck deck;
    string p1, p2;
    Card card1, card2;
    int score1, score2, ties;
    cout << "Enter the name of the first player: ";
    cin >> p1;
    cout << "Enter the name of the second player: ";
    cin >> p2;
    cout << endl << " Original Deck" << endl;
    deck.display();
    deck.shuffle();
    cout << endl << " Shuffled Deck" << endl;
    deck.display();
    cout << endl;

    /* format for each game.
    Game 1
    --------
            Aquaman=>9C
            Batman=>8H
    Aquaman=> Winner
    */
    for(int i = 1; i <= 26; ++i){
        cout << "Game " << i << endl;
	    cout << "--------" << endl;
	    cout << "\t" << p1 << "=>";
        card1 = deck.deal();
        card1.display();
        cout << endl;
        cout << "\t" << p2 << "=>";
        card2 = deck.deal();
        card2.display();
        cout << endl;
        if(card1.compare(card2) == 1){
            cout << p1 << "=> Winner";
            score1++;
        }
        else if(card1.compare(card2) == -1){
            cout << p2 << "=> Winner";
            score2++;
        }
        else{
            cout << "Tie game";
            ties++;
        }        
        cout << endl << endl;
    }
    
    cout << "------Final Stats------" << endl;
    cout << setw(7 + p1.size()) << p1 << " vs. " + p2 << endl;
    cout << left << setw(7) << "Wins" << left << setw(p1.size() + 5) << score1 << score2 <<endl;
    cout << left << setw(7) << "Losses" << left << setw(p1.size() + 5) << score2 << score1 <<endl;
    cout << left << setw(7) << "Ties" << left << setw(p1.size() + 5) << ties << ties<< endl;


    return 0;
}
