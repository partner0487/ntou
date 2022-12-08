#include "iostream"
using namespace std;

struct node{
    int v;
    node *l, *r;
    node(){
        l = r = NULL;
    }
};

void insert(node *&now, int n){
    if(now == NULL){
        now = new node;
        now->v = n;
        return;
    }
    if(n < now->v) insert(now->l, n);
    else          insert(now->r, n);
}
void print(node *now){
    if(now){
        cout << now->v << " ";
        print(now->l);
        print(now->r);
    }
}

int main(){
    node *root = NULL;
    int n;
    while(cin >> n){
        insert(root, n);
        print(root);
        cout << endl;
    }
}