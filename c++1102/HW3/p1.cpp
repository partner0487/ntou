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
template<class type>
void preorder(node<type> *now){
    if(now != NULL){
        cout << now->d << " ";
        preorder(now->l);
        preorder(now->r);
    }
}
template<class type>
void postorder(node<type> *now){
    if(now != NULL){
        postorder(now->l);
        postorder(now->r);
        cout << now->d << " ";
    }
}

void testp1int(){
    node<int> *root = NULL;
    for(int i = 1, it; i <= 15; i++){
        it = rand() % 15;
        cout << it << " ";
        insert(root, it);
    }
    cout << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
}

void testp1float(){
    node<float> *root = NULL;
    float it;
    for(int i = 1; i <= 15; i++){
        it = 1.0 + (float)(rand() % 8) * 0.01f;
        cout << it << " ";
        insert(root, it);
    }
    cout << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
}

int main(){
    testp1int();
    cout << endl;
    testp1float();
    cout << endl;
}