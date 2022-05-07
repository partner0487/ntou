#include "iostream"
#include "card.h"
using namespace std;

void printcard(card *c){ // print five card
    for(int i = 0; i < 5; i++){
        cout << i + 1 << " "; // print the index of the card to let player more easily to choose card to swap
        c[i].print(); // print each card's suit and number, in order.
        cout << endl;
    }
    cout << endl;
}

bool cmp(card a, card b){
    if(a.number == b.number) return a.suit < b.suit;
    return a.number < b.number; // sort the card 
    // first sort : number, second sort : suit;
}

int main(){
    int n;
    deck all; // a whole deck
    card a[5], b[5]; // the card A player has and the card B player has
    int pa = 0, pb = 0, pen = 1; // pa = the point A get, pb = the point B get.
    all.shuffle();

    while(cin >> n){
        if(n == 1){ // if input 1, then start/restart the game
            cout << "new game\n";
            all.top = pa = pb = 0; // all.top must start at 0 in the beginning
            // point a and point b must be 0
            all.shuffle();
        }
        else if(n == 2){
            for(int i = 0; i < 5; i++){
                if(all.top >= 52){ // if their isn't any card left, then break
                    cout << "no card left" << endl;
                    pen = 0; // in line 45 to pending whether the game should be restarted
                    break;
                }
                // deal the card to A player and B player
                a[i] = all.get(); 
                b[i] = all.get();
            }
            if(!pen){ // pen is initially 1, if pen is 0, meaning that the game should be restarted
                cout << "new game\n";
                all.top = pa = pb = 0;
                all.shuffle();
                continue;
            }
            sort(a, a + 5, cmp); sort(b, b + 5, cmp); // sort the card to make the card more readale

            // let A player and B player know the card they have
            printcard(a); 
            printcard(b);

            int ac, bc; // the index of player's card players choose to swap (1' base)
            cout << "a choose to swap: ";
            cin >> ac;
            cout << "b choose to swap: ";
            cin >> bc;
            swap(a[ac - 1], b[bc - 1]);

            sort(a, a + 5, cmp); sort(b, b + 5, cmp); // sort the card to make it more readable
            printcard(a), printcard(b); // let players know the result
            
            pa += check_five_card(a), pb = check_five_card(b); // count the point playerA and playerB get
            
            cout << "point a: " << pa << endl; // print pointA
            cout << "point b: " << pb << endl; // print pointB

            // determine which player win
            if(pa == pb) cout << "tie";
            else pa < pb ? cout << "b win" : cout << "a win";
            cout << endl;
        }
        else break;
    }
}   