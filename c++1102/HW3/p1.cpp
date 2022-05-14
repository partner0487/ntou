/*
Author: Xiaoyo
num: 01057020
time: 2022 / 05 / 14
//*/
#include "iostream"
#include "time.h"
using namespace std;

template<class type>
struct node{
    node<type> *l,  *r;
    type d;
};

template<class type>
void insert(node<type> *&now, type v){
    if(now == NULL){
        now = new node<type>();
        now->d = v;
        return;
    }
    if(v > now->d) insert(now->r, v);
    else           insert(now->l, v);
}
template<class type>
void inorder(node<type> *now){
    if(now != NULL){
        inorder(now->l);
        cout << now->d << " ";
        inorder(now->r);
    }
}

void testp1(){
    node<int> *root = new node<int>();
    for(int i = 1, it; i <= 15; i++){
        it = rand() % 15;
        cout << it << " ";
        insert(root, it);
    }
    cout << endl;
    inorder(root);
}

int main(){
    testp1();
    
}