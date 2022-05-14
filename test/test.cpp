#include "bits/stdc++.h"
using namespace std;

struct node{
    node *l, *r;
    int d;
};

void insert(node *&now, int it){
    if(now == NULL){
        now = new node();
        now->d = it;
        return;
    }
    if(it > now->d) insert(now->r, it);
    else            insert(now->l, it);
}

void printInOrder(node *now){
    if(now != NULL){
        printInOrder(now->l);
        cout << now->d << " ";
        printInOrder(now->r);
    }
}

void test(){
    node *root = new node();
    for(int i = 1, it; i <= 15; i++){
        it = rand() % 15;
        cout << it << " ";
        insert(root, it);
    }
    cout << endl << "InORDER" << endl;
    printInOrder(root);
}

int main(){
    test();
}