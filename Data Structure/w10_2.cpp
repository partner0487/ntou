#include "iostream"
using namespace std;

struct LIST{
    LIST *nxt, *lst;
    float coef;
    int expon;
};

LIST *root[2];
LIST *last[2];

void init(){
    root[0] = root[1] = last[0] = last[1] = new LIST;
    root[0]->nxt = last[0];
    last[0]->lst = root[0];
    root[1]->nxt = last[1];
    last[1]->lst = root[1];
}

void push(int pos, int n, int k){
    
}

int main(){
    init();

    int n, k;
    while(cin >> n){
        if(n == -1) break;
        cin >> k;
        push(0, n, k);
    }
    while(cin >> n){
        if(n == -1) break;
        cin >> k;
        push(1, n, k);
    }
}