#include "iostream"
using namespace std;

struct node{
    node *nxt, *lst;
    int n;
};
node *st = new node;
node *ls = new node;

void push_back(int n){
    node *New = new node;
    New->n = n;
    node *tmp = ls->lst;
    New->lst = tmp;
    New->nxt = ls;
    tmp->nxt = New;
    ls->lst = New;
}

int main(){
    st->nxt = ls;
    ls->lst = st;
    int n;
    while(cin >> n)
        push_back(n);
    for(node *i = ls->lst; i != st; i = i->lst)
        cout << i->n << (i->lst == st ? "" : " ");
    cout << endl;
}