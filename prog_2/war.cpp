// John Fahriddinov
// CECS 325-02
// Prog 2 - One Card War (with Vectors)
// 09/30/25
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.


#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;
 
class Card
{
    public:

        Card(char r, char s){
            rank = r;
            suit = s;
        }

        void display(){
            if(rank == 'T')
                cout << "10" << suit;
            else    
            cout << rank << suit; 
            
        }

        int compare(Card c){
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
};

class Deck
{
    public:
        Deck(){
            char suit[] = {'C', 'S', 'D', 'H'};
            char rank[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
            int index = 0;
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 13; j++){
                    cards.push_back(Card(rank[j], suit[i]));
                }
            }
            current_card_index = 0;
        }

        Card deal(){
            if(isEmpty())
                throw runtime_error("Deck is empty");
                
            return cards.at(current_card_index++);
            
        }

        void display(){
            int index = 0;
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 12; j++){
                    cards[index++].display();
                    cout << ',';
                }
                cards[index++].display();
                cout << endl;
            }
        }

        void shuffle(){
            for(int i = 0; i < 500; i++){
                int x = rand()%52;
                int y = rand()%52;
                Card holder = cards[x];
                cards[x] = cards[y];
                cards[y] = holder;
            }
        }

        bool isEmpty(){
            return current_card_index >= cards.size();
        }

    private: 
        vector<Card> cards;
        int current_card_index;
};

struct Player {
    string name;
    int win;
    int lose;
    int tie;
};


int main(){
    srand(time(NULL));
    Deck deck;
    int numGames;
    Player player1 = {"", 0, 0, 0}, player2 = {"", 0, 0, 0};

    cout << "Enter the name of the first player: ";
    cin >> player1.name;
    cout << "Enter the name of the second player: ";
    cin >> player2.name;
    cout << "Enter the number of games to be played: ";
    cin >> numGames;
    cout << endl << " Original Deck" << endl;
    deck.display();
    deck.shuffle();
    cout << endl << " Shuffled Deck" << endl;
    deck.display();
    cout << endl;

    for(int i = 1; i <= numGames; ++i){
        try { 
            Card card1 = deck.deal();
            Card card2 = deck.deal();
        
            cout << "Game " << i << endl;
            cout << "--------" << endl;
            cout << "\t" << player1.name << "=>";
            card1.display();
            cout << endl;
            cout << "\t" << player2.name << "=>";
            card2.display();
            cout << endl;
            int res = card1.compare(card2);
            if(res == 1){
                cout << player1.name << "=> Winner";
                player1.win++;
                player2.lose++; 
            }
            else if(res == -1){
                cout << player2.name << "=> Winner";
                player2.win++;
                player1.lose++;
            }
            else{
                cout << "Tie game";
                player1.tie++;
                player2.tie++;
            }        
            cout << endl << endl;
        } catch (runtime_error& e) {
            cout << "Error - " << e.what() << endl;
            break;
        }
    }
    cout << "------Final Stats------" << endl;
    cout << setw(7 + player1.name.size()) << player1.name << " vs. " + player2.name << endl;
    cout << left << setw(7) << "Wins" << left << setw(player1.name.size() + 5) << player1.win << player2.win <<endl;
    cout << left << setw(7) << "Losses" << left << setw(player1.name.size() + 5) << player1.lose << player2.lose <<endl;
    cout << left << setw(7) << "Ties" << left << setw(player1.name.size() + 5) << player1.tie << player2.tie << endl;


    return 0;
}
