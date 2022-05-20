/*
Author: Xiaoyo
num: 01057020
time: 2022 / 05 / 14
//*/
#include "iostream"
#include "time.h"
using namespace std;

void printFun(int x){
    cout << x << " ";
}

int cmp(int a, int b){
    if(a > b) return 1;
    else if(a < b) return -1;
    else return 0;
}

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
    if(cmp(v, now->d) > 0) insert(now->r, v);
    else                   insert(now->l, v);
}
template<class type>
void inorder(node<type> *now){
    if(now != NULL){
        inorder(now->l);
        printFun(now->d);
        inorder(now->r);
    }
}
template<class type>
void preorder(node<type> *now){
    if(now != NULL){
        printFun(now->d);
        preorder(now->l);
        preorder(now->r);
    }
}
template<class type>
void postorder(node<type> *now){
    if(now != NULL){
        postorder(now->l);
        postorder(now->r);
        printFun(now->d);
    }
}

template<class type>
type find(node<type> *&now, int t){
    if(t){
        if(now->l == NULL){
            type ret = now->d;
            now = now->r;
            return ret;
        }
    }
    else{
        if(now->r == NULL){
            type ret = now->d;
            now = now->l;
            return ret;
        }
    }
    return t ? find(now->l, t) : find(now->r, t);
}

template<class T, class K>
bool deletenode(node<T> *&now, K key){
    if(now == NULL) return 0;
    if(cmp(key, now->d) > 0) deletenode(now->r, key);
    else if(cmp(key, now->d) < 0) deletenode(now->l, key);
    else now->d = now->r == NULL ? find(now->l, 0) : find(now->r, 1);
    return 1;
}

void testInt(){
    node<int> *root = NULL;
    for(int i = 1, it; i <= 15; i++){
        it = rand() % 15;
        cout << it << " ";
        insert(root, it);
    }
    cout << endl;
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    cout << "testDelete: " << endl;
    cout << (deletenode(root, 11) ? "success" : "fail") << endl;
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
}

int main(){
    testInt();
    cout << endl;
}