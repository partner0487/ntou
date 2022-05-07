#include "map"
#include "string"
#include "iostream"
#include "algorithm"
#include "iomanip"
#ifndef CARD  
#define CARD
using namespace std;

// using the rule deuces plays in Taiwan
string CARD_SIGNED[4] = { "Spades" ,"Hearts", "Diamonds", "Clubs" };
string CARD_NUMBER[13] = { "ace","two" ,"three","four","five" ,"six","seven" ,"eight" ,"nine"
                          ,"ten","jack","quen","king" };

struct card{ // make a card
    int suit, number; // suit and number index
    card(){ // initial
        suit = 0, number = 0;
    }
    card(int a, int b){ // specify the card
        suit = a, number = b;
    }
    void print(){ // print the card's suit and number, in order
        cout << fixed << setw(10) << right << CARD_SIGNED[suit] << "\t" << CARD_NUMBER[number];
    }
};
struct deck{ // make a deck
    int top; // the top card in the deck
    card arr[52]; // initial
    void print(){ // print the cards which have not been drawn
        for(int i = top; i < 52; i++){
            cout << fixed << setw(10) << right << CARD_SIGNED[arr[i].suit] << "\t" << CARD_NUMBER[arr[i].number] << endl;
        }
    }
    void shuffle(){ // shuffle :)
        srand(time(NULL));
        for(int i = top; i < 52; i++){
            int tmp = rand() % (52 - top) + top;
            swap(arr[i], arr[tmp]);
        }
    }
    card get(){ // draw the top card of the deck
        return arr[top++];
    }
    deck(){ // initial the deck
        top = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j <= 12; j++){
                arr[i * 13 + j].suit = i;
                arr[i * 13 + j].number = j;
            }
        }
    }
};
int check_three_card(card *arr){
    int de[4] = {}, num[13] = {}; // the number of the deck and the number
    map<int, int> mem; // record the maximum suit in the cards
    fill(de, de + 4, 0); // empty
    fill(num, num + 13, 0); // empty
    for(int i = 0; i < 3; i++){ // recording
        mem[arr[i].number] = max(arr[i].suit, mem[arr[i].number]); // the maximum suit that the number have
        de[arr[i].suit]++; // the number of the suit
        num[arr[i].number]++; // the number of the number
    }
    bool ispair = 0, isthreekind = 0; // determine whether is pair or three
    for(int i = 0; i < 13; i++){
        if(num[i] == 3) // three
            isthreekind = 1;
        if(num[i] == 2) ispair = 1; // pair
    }

    // record the code of card type
    string res;
    if(isthreekind){
        res += 'c';
    }
    else if(ispair){
        res += 'b';
    }
    else{
        res += 'a';
    }
    if(isthreekind or ispair){ // if the type is pair or three
        for(int i = 0; i < 13; i++)
            if(num[i] >= 2){
                res += ('a' + i); // record the code of number
                res += ('a' + mem[i]); // record code of suit
            }
    }
    else{ // if not
        string maxx = ""; // find the maximum card 
        for(int i = 0; i < 3; i++){
            string tmp;
            tmp += ('a' + arr[i].suit);
            tmp += ('a' + arr[i].number);
            maxx = max(tmp, maxx);
        }
        res = maxx;
    }
    int ret = 0;
    for(int i = res.length() - 1, index = 1; i >= 0; i--, index *= 1001)
        ret += res[i] * index; // make the sum
    return ret;
}

int checkPairFullHouseThree(int *Num){ // determine whether have pair, fullhouse, three
    int p1 = 0, p2 = 0;
    int i = 0;
    
    for(i = 0; i < 13; i++)
        if(Num[i] >= 2){ 
            p1 = Num[i]; // pair or three or nothing
            i++;
            break;
        }
    for(; i < 13; i++)
        if(Num[i] >= 2)
            p2 = Num[i]; // pair or three or nothing
    if(p1 == 2 and p2 == 2) return 2; // two pairs
    else if((p1 == 2 and p2 == 3) or (p1 == 3 and p2 == 2)) return 5; // full house
    else if(p1 == 2 and p2 != 2) return 1; // pair
    else if(p2 == 3 or p1 == 3) return 3; // three of kind
    else if(p1 == 4) return 4; // four of kind
    else return -1;
}

int checkStraightFlush(int Suit[], int Num[]){ // check flush and straight
    int straight = 0, flush = 0;
    // check straight
    if(Num[11] == 1 and Num[12] == 1 and Num[1] == 1 and Num[2] == 1 and Num[0] == 1)
        straight = 1;
    else if(Num[12] == 1 and Num[0] == 1 and Num[1] == 1 and Num[2] == 1 and Num[3] == 1)
        straight = 1;
    else
        for(int i = 0; i < 13 - 4; i++)
            if(Num[i] == 1 and Num[i + 1] == 1 and Num[i + 2] == 1 and Num[i + 3] == 1 and Num[i + 4] == 1)
                straight = 1;
    // check flush
    for(int i = 0; i < 4; i++)
        if(Suit[i] == 5){
            flush = 1; 
            break;
        }

    if(straight == 1 and flush == 1) return 3; // if both -> straight flush
    else if(straight == 1) return 2; // straight
    else if(flush == 1) return 1; // flush
    else return -1; 
}
int check_five_card(card *arr){
    int de[4] = {}, num[13] = {}, dec[4][13]; // the number of the suit, the number of the num, deck
    map<int, int> mem; // the suit that the max num is
    mem.clear();
    fill(de, de + 4, 0); // empty
    fill(num, num + 13, 0);
    for(int i = 0; i < 5; i++){
        mem[arr[i].number] = max(arr[i].suit, mem[arr[i].number]); // record the max suit that the num is
        dec[arr[i].suit][arr[i].number] = 1; // record whether the card has been used
        de[arr[i].suit]++; // record the num of the suit
        num[arr[i].number]++; // record the num of the num
    }
    string res;
    int pfht = checkPairFullHouseThree(num), sf = checkStraightFlush(de, num);
    
    if(pfht == 1) // pair
        res += 'b';
    else if(pfht == 2) // two pairs
        res += 'c';
    else if(pfht == 3) // three
        res += 'd';
    else if(pfht == 4) // four of a kind
        res += 'h';
    else if(sf == 3) // straight flush
        res += 'i';
    else if(sf == 2) // straight
        res += 'e'; 
    else if(sf == 1) // flush
        res += 'f';
    else if(pfht == 5) // full house
        res += 'g';
    else
        res += 'a';

    // find the max num
    if(sf != -1){ // if the cards is straight or flush or straight flush
        if(sf != 1){ // straight
            for(int i = 12; i >= 0; i--){
                if(num[i] == 1){
                    res += char('a' + i); // first compare the number
                    res += char('a' + mem[num[i]]);
                    break;
                }
            }
        }
        else{ // flush
            for(int i = 12; i >= 0; i--){
                if(num[i] == 1){ 
                    res += char('a' + mem[num[i]]); // first compare the suit
                    res += char('a' + i);
                    break;
                }
            }
        }
    }
    else if(pfht != -1){ // pair or fullhouse or three or four
        for(int i = 12; i >= 0; i--){ 
            if((pfht == 3 or pfht == 5) and num[i] >= 3){
                res += char('a' + i); // three or fullhouse
                for(int j = 3; j >= 0; j--){
                    if(dec[j][i]){
                        res += char('a' + j);
                        break;
                    }
                }
                break;
            }
            else if((pfht != 3 and pfht != 5) and num[i] == 2){
                res += char('a' + i); // pair, two pairs, four
                for(int j = 3; j >= 0; j--){
                    if(dec[j][i]){
                        res += char('a' + j);
                        break;
                    }
                }
                break;
            }
        }
    }
    else{
        string maxx = "";
        for(int i = 0; i < 5; i++){
            string tmp;
            tmp += ('a' + arr[i].suit);
            tmp += ('a' + arr[i].number);
            maxx = max(tmp, maxx);
        }
    }
    int ret = 0;
    for(int i = res.length() - 1, index = 1; i >= 0; i--, index *= 1001)
        ret += res[i] * index; // counting the sum
    return ret;
}

#endif