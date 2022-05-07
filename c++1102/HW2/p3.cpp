#include "iostream"
#include "algorithm"
#include "card.h"
#include "stdlib.h"
#include "time.h"

void printcard(card *c){ // print thirteen card
    for(int i = 0; i < 13; i++){
        cout << i + 1 << " "; // print the index of the card to let player more easily to choose card to swap
        c[i].print();// print each card's suit and number, in order.
        cout << endl;
    }
    cout << endl;
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

bool cmp(card a, card b){
    if(a.number == b.number) return a.suit < b.suit;
    return a.number < b.number;// sort the card
    // first sort : number, second sort : suit.
}

void init(int *a){ // initial the index manmachine's choosing
    srand(time(NULL));
    for(int i = 0; i < 13; i++){
        int temp = rand() % (13 - 0);
        swap(a[i], a[temp]);
    }
}

int main(){
    deck all; // a whole deck
    all.shuffle();
    card a[13], b[13], c[13], d[13]; // the card playerA and playerB and playerC and playerD has

    int n, p, ak, pen = 1; // p : how many player. ak is to determine who is the player should swap the card with playerA 
    int pa = 0, pb = 0, pc = 0, pd = 0;  // the point each player get

    // the index of (each manmachine choose to swap), (playerB, C, D choose top, mid, down deck)
    int choose[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}, 
    bchoose[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
    cchoose[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
    dchoose[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    init(choose); // initial 
    init(bchoose); init(cchoose); init(dchoose);

    while(cin >> n){
        if(n == 1){ // if input 1, thn start/ restart the game
            cout << "new game\n";
            all.shuffle();
            all.top = pa = pb = pc = pd = 0; // all.top must must start at 0 in the beginning
            cout << "playerA choose a player to swap the cards ";
            cin >> ak;
        }
        else if(n == 2){
            for(int i = 0; i < 13; i++){
                if(all.top >= 52){ // if their isn't any card left, then break
                    cout << "no card left" << endl;
                    pen = 0; // in line 71 to pending whether the game should be restarted
                    break;
                }
                // deal the card to A player and B player
                a[i] = all.get();
                b[i] = all.get();
                c[i] = all.get();
                d[i] = all.get();
            } 
            if(!pen){ // pen is initially 1, if pen is 0, meaning that the game should be restarted
                cout << "new game\n";
                all.top = pa = pb = pc = pd = 0;
                all.shuffle();
                continue;
            }
            // sort the card to make the card more readale
            sort(a, a + 13, cmp); sort(b, b + 13, cmp);
            sort(c, c + 13, cmp); sort(d, d + 13, cmp);

            // let every players knows the card they have
            printcard(a);
            printcard(b);
            printcard(c);
            printcard(d);

            int a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3;
            // the index of player's card players choose to swap (1' base)
            cout << "a player choose card to swap: ";
            cin >> a1 >> a2 >> a3;

            b1 = choose[0], b2 = choose[1], b3 = choose[2];
            c1 = choose[3], c2 = choose[4], c3 = choose[5];
            d1 = choose[6], d2 = choose[7], d3 = choose[8];

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
            
            int j = 0;
            // choose three card in top deck
            for(int i = 0; i < 3; i++) btop[i] = b[bchoose[j++] - 1];
            // choose five card in mid deck
            for(int i = 0; i < 5; i++) bmid[i] = b[bchoose[j++] - 1];
            // choose five card in down deck
            for(int i = 0; i < 5; i++) bdown[i] = b[bchoose[j++] - 1];

            j = 0;
            // choose three card in top deck
            for(int i = 0; i < 3; i++) ctop[i] = c[cchoose[j++] - 1];
            // choose five card in mid deck
            for(int i = 0; i < 5; i++) cmid[i] = c[cchoose[j++] - 1];
            // choose five card in down deck
            for(int i = 0; i < 5; i++) cdown[i] = c[cchoose[j++] - 1];
                
            j = 0;
            // choose three card in top deck
            for(int i = 0; i < 3; i++) dtop[i] = d[dchoose[j++] - 1];
            // choose five card in mid deck
            for(int i = 0; i < 5; i++) dmid[i] = d[dchoose[j++] - 1];
            // choose five card in down deck
            for(int i = 0; i < 5; i++) ddown[i] = d[dchoose[j++] - 1];
            
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
            cout << "point c: " << pc << endl; // print the final pointC
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
        else break;
    }
}