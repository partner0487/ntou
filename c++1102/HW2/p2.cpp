#include "iostream"
#include "cstdlib"
#include "algorithm"
#include "card.h"
using namespace std;

void printcard(card *c){ // print thirteen card
    for(int i = 0; i < 13; i++){
        cout << i + 1 << " "; // print the index of the card to let player more easily to choose card to swap
        c[i].print();  
        cout << endl;
    }
    cout << endl;
}

bool cmp(card a, card b){
    if(a.number == b.number) return a.suit < b.suit;
    return a.number < b.number; // sort the card
    // first sort : number, second sort : suit.
}

void printcard3(card *c){ // print each player's top deck(3 card)
    for(int i = 0; i < 3; i++){
        cout << i + 1 << " "; // print the index of the card
        c[i].print(); // print each card's suit and number, in order.
        cout << endl;
    }
    cout << endl;
}
void printcard5(card *c){ // print each player's mid and down deck(5 card)
    for(int i = 0; i < 5; i++){
        cout << i + 1 << " "; // print the index of the card
        c[i].print(); // print each card's suit and number, in order.
        cout << endl;
    }
    cout << endl;
}

int main(){
    deck all; // a whole deck
    all.shuffle();
    card a[13], b[13], c[13], d[13]; // the card playerA and playerB and playerC and playerD has
    
    int n, p, ak, pen = 1; // p : how many player. ak is to determine who is the player should swap the card with playerA 
    int pa = 0, pb = 0, pc = 0, pd = 0; // the point each player get
    
    while(cin >> n){
        if(n == 1){ // if input 1, thn start/ restart the game
            cout << "new game\n";
            all.shuffle();
            all.top = pa = pb = pc = pd = 0; // all.top must must start at 0 in the beginning
            cout << "how many players: ";
            cin >> p; // input how many player
            if(p == 4){
                cout << "playerA choose to swap: ";
                cin >> ak;
            }
        }
        else if(n == 2){
            if(p == 2){ // if there are two players
                for(int i = 0; i < 13; i++){// if their isn't any card left, then break
                    if(all.top >= 52){
                        cout << "no card left" << endl;
                        pen = 0;// in line 71 to pending whether the game should be restarted
                        break;
                    }
                    // deal the card to A player and B player
                    a[i] = all.get();
                    b[i] = all.get();
                }
                if(!pen){ // pen is initially 1, if pen is 0, meaning that the game should be restarted
                    all.top = 0;
                    pa = pb = 0;
                    all.shuffle();
                    continue;
                }
                sort(a, a + 13, cmp); sort(b, b + 13, cmp); // sort the card to make the card more readale
                
                // let A player and B player know the card they have
                printcard(a);
                printcard(b);

                int a1, a2, a3, b1, b2, b3; // the index of player's card players choose to swap (1' base)

                cout << "a player choose card to swap: ";
                cin >> a1 >> a2 >> a3;

                cout << "b player choose card to swap: ";
                cin >> b1 >> b2 >> b3;

                swap(a[a1 - 1], b[b1 - 1]);
                swap(a[a2 - 1], b[b2 - 1]);
                swap(a[a3 - 1], b[b3 - 1]);

                sort(a, a + 13, cmp); sort(b, b + 13, cmp); // sort the card to make it more readable
                printcard(a), printcard(b);// let players know the result

                card atop[3], amid[5], adown[5], btop[3], bmid[5], bdown[5];
                // the deck of each player choose to compare
                
                cout << "a choose top: ";
                for(int i = 0, k; i < 3; i++){ // choose three card in top deck
                    cin >> k; // input the index
                    atop[i] = a[k - 1];
                }
                cout << "a choose mid: ";
                for(int i = 0, k; i < 5; i++){ // choose five card in mid deck
                    cin >> k; // input the index
                    amid[i] = a[k - 1];
                }
                cout << "a choose down: ";
                for(int i = 0, k; i < 5; i++){ // choose five card in down deck
                    cin >> k; // input the index
                    adown[i] = a[k - 1];
                }

                cout << "b choose top: ";
                for(int i = 0, k; i < 3; i++){// choose three card in top deck
                    cin >> k;// input the index
                    btop[i] = b[k - 1];
                }
                cout << "b choose mid: ";
                for(int i = 0, k; i < 5; i++){// choose five card in mid deck
                    cin >> k;// input the index
                    bmid[i] = b[k - 1];
                }
                cout << "b choose down: ";
                for(int i = 0, k; i < 5; i++){// choose five card in down deck
                    cin >> k;// input the index
                    bdown[i] = b[k - 1];
                }
                // the comparison is only acceptalbe if and only if the point Top <= mid <= down deck
                if(check_three_card(atop) <= check_five_card(amid) && check_five_card(amid) <= check_five_card(adown)){
                    pa += check_three_card(atop);
                    pa += check_five_card(amid);
                    pa += check_five_card(adown);    
                }
                if(check_three_card(btop) <= check_five_card(bmid) && check_five_card(bmid) <= check_five_card(bdown)){
                    pb += check_three_card(btop);
                    pb += check_five_card(bmid);
                    pb += check_five_card(bdown);
                }
                // let players know the result
                printcard3(atop); printcard3(btop);
                printcard5(amid); printcard5(bmid);
                printcard5(adown); printcard5(bdown);

                cout << "point a: " << pa << endl; // print the final pointA
                cout << "point b: " << pb << endl; // print the final pointB
                
                // determine which player win
                if(pa == pb) cout << "tie";
                else pa < pb ? cout << "b win" : cout << "a win";
                cout << endl;
            }
            else{ // if there are four players
                for(int i = 0; i < 13; i++){ 
                    if(all.top >= 52){  // if their isn't any card left, then break
                        cout << "no card left" << endl;
                        pen = 0;
                        break;
                    }
                    a[i] = all.get();
                    b[i] = all.get();
                    c[i] = all.get();
                    d[i] = all.get();
                }
                if(!pen){ //  pen is initially 1, if pen is 0, meaning that the game should be restarted
                    cout << "new game\n";
                    all.top = pa = pb = pc = pd = 0; 
                    all.shuffle();
                    continue;
                }
                // sort the card to make the card more readale
                sort(a, a + 13, cmp); sort(b, b + 13, cmp); 
                sort(c, c + 13, cmp); sort(d, d + 13, cmp);

                // let every player knows the card they have
                printcard(a); 
                printcard(b);
                printcard(c);
                printcard(d);

                int a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3; // the index of player's card players choose to swap (1' base)
                cout << "a player choose card to swap: ";
                cin >> a1 >> a2 >> a3;

                cout << "b player choose card to swap: ";
                cin >> b1 >> b2 >> b3;

                cout << "c player choose card to swap: ";
                cin >> c1 >> c2 >> c3;

                cout << "d player choose card to swap: ";
                cin >> d1 >> d2 >> d3;
                
                // if bk = 2, meaning that playerA swaps the card with playerB, and the playerC swap and with D
                if(ak == 2){
                    swap(a[a1], b[b1]);
                    swap(a[a2], b[b2]);
                    swap(a[a3], b[b3]);
                    swap(c[c1], d[d1]);
                    swap(c[c2], d[d2]);
                    swap(c[c3], d[d3]);
                }
                // bk = 3, meaning that playerA swaps the card with playerC, and the playerB swaps the card with playerD
                else if(ak == 3){
                    swap(a[a1], c[c1]);
                    swap(a[a2], c[c2]);
                    swap(a[a3], c[c3]);
                    swap(b[b1], d[d1]);
                    swap(b[b2], d[d2]);
                    swap(b[b2], d[d2]);
                }
                // if bk = 4, meaning that playerA swaps the card with playerD, and the playerB swaps the card with playerC
                else{
                    swap(a[a1], d[d1]);
                    swap(a[a2], d[d2]);
                    swap(a[a3], d[d3]);
                    swap(c[c1], b[b1]);
                    swap(c[c2], b[b2]);
                    swap(c[c3], b[b3]);
                }

                sort(a, a + 13, cmp); sort(b, b + 13, cmp); // sort the card to make it more readable
                sort(c, c + 13, cmp); sort(d, d + 13, cmp); // sort the card to make it more readable
                // let players know the card they have
                printcard(a);
                printcard(b);
                printcard(c);
                printcard(d);

                card atop[3], amid[5], adown[5], btop[3], bmid[5], bdown[5],
                ctop[3], cmid[5], cdown[5], dtop[3], dmid[5], ddown[5];
                // the deck of each player choose to compare

                cout << "a choose top: ";
                for(int i = 0, k; i < 3; i++){ // choose three card in top deck
                    cin >> k;  // input the index
                    atop[i] = a[k - 1];
                }
                cout << "a choose mid: ";
                for(int i = 0, k; i < 5; i++){ // choose five card in mid deck
                    cin >> k; // input the index
                    amid[i] = a[k - 1];
                }
                cout << "a choose down: ";
                for(int i = 0, k; i < 5; i++){ // choose five card in down deck
                    cin >> k; // input the index
                    adown[i] = a[k - 1];
                }
                
                cout << "b choose top: ";
                for(int i = 0, k; i < 3; i++){ // choose three card in top deck
                    cin >> k; // input the index
                    btop[i] = b[k - 1];
                }
                cout << "b choose mid: ";
                for(int i = 0, k; i < 5; i++){ //choose five card in mid deck
                    cin >> k; // input the index
                    bmid[i] = b[k - 1];
                }
                cout << "b choose down: ";
                for(int i = 0, k; i < 5; i++){ // choose five card in down deck
                    cin >> k; // input the index
                    bdown[i] = b[k - 1];
                }

                cout << "c choose top: ";
                for(int i = 0, k; i < 3; i++){// choose three card in top deck
                    cin >> k; // input the index
                    ctop[i] = c[k - 1];
                }
                cout << "c choose mid: ";
                for(int i = 0, k; i < 5; i++){ //choose five card in mid deck
                    cin >> k; // input the index
                    cmid[i] = c[k - 1];
                }
                cout << "c choose down: ";
                for(int i = 0, k; i < 5; i++){// choose five card in down deck
                    cin >> k; // input the index
                    cdown[i] = c[k - 1];
                }

                cout << "d choose top: ";
                for(int i = 0, k; i < 3; i++){// choose three card in top deck
                    cin >> k; // input the index 
                    dtop[i] = d[k - 1];
                }
                cout << "d choose mid: ";
                for(int i = 0, k; i < 5; i++){//choose five card in mid deck
                    cin >> k; // input the index
                    dmid[i] = d[k - 1];
                }
                cout << "d choose down: ";
                for(int i = 0, k; i < 5; i++){// choose five card in down deck
                    cin >> k; // input the index
                    ddown[i] = d[k - 1];
                }
                // the comparison is only acceptalbe if and only if the point Top <= mid <= down deck
                if(check_three_card(atop) <= check_five_card(amid) && check_five_card(amid) <= check_five_card(adown)){
                    pa += check_three_card(atop);
                    pa += check_five_card(amid);
                    pa += check_five_card(adown);
                }
                if(check_three_card(btop) <= check_five_card(bmid) && check_five_card(bmid) <= check_five_card(bdown)){
                    pb += check_three_card(btop);
                    pb += check_five_card(bmid);
                    pb += check_five_card(bdown);
                }
                if(check_three_card(ctop) <= check_five_card(cmid) && check_five_card(cmid) <= check_five_card(cdown)){
                    pc += check_three_card(ctop);
                    pc += check_five_card(cmid);
                    pc += check_five_card(cdown);
                }
                if(check_three_card(dtop) <= check_five_card(dmid) && check_five_card(dmid) <= check_five_card(ddown)){
                    pd += check_three_card(dtop);
                    pd += check_five_card(dmid);
                    pd += check_five_card(ddown);
                }
                // let players know the result
                printcard3(atop); printcard3(btop); printcard3(ctop); printcard3(dtop);
                printcard5(amid); printcard5(bmid); printcard5(cmid); printcard5(dmid);
                printcard5(adown); printcard5(bdown); printcard5(cdown); printcard5(ddown);
                
                cout << "point a: " << pa << endl; // print the final pointA
                cout << "point b: " << pb << endl; // print the final pointB
                cout << "point c: " << pc << endl;// print the final pointC
                cout << "point d: " << pd << endl; // print the final pointD

                // determine which player win
                if(pa == pb == pc == pd) cout << "tie";
                else{
                    if(pa < pb){
                        if(pc < pd) pb < pd ? cout << "d win" : cout << "b win";
                        else pb < pc ? cout << "c win" : cout << "b win";
                    }
                    else{
                        if(pc < pd) pa < pd ? cout << "d win" : cout << "a win";
                        else pa < pc ? cout << "c win" : cout << "a win";
                    }
                }
                cout << endl;
            }
        }
        else break;
    }
}