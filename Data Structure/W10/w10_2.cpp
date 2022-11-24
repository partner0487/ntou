#include "iostream"
using namespace std;

struct LIST{
    LIST *nxt, *lst;
    float coef;
    int expon;
};

LIST *root[2];
LIST *last[2];
LIST *ansST[2];
LIST *ansED[2];

void init(){
    ansST[0] = new LIST;
    ansST[1] = new LIST;
    ansED[0] = new LIST;
    ansED[1] = new LIST;
    root[0] = new LIST;
    root[1] = new LIST;
    last[0] = new LIST;
    last[1] = new LIST;
    root[0]->nxt = last[0];
    last[0]->lst = root[0];
    root[1]->nxt = last[1];
    last[1]->lst = root[1];
    ansST[0]->nxt = ansED[0];
    ansED[0]->lst = ansST[0];
    ansST[1]->nxt = ansED[1];
    ansED[1]->lst = ansST[1];
}

void push(int pos, float n, int k){
    LIST *now = root[pos]->nxt;
    LIST *PU = new LIST;
    PU->coef = n, PU->expon = k;
    if(now == last[pos]){
        PU->lst = root[pos];
        root[pos]->nxt = PU;
        PU->nxt = last[pos];
        last[pos]->lst = PU;
    }
    else{
        LIST *i = root[pos]->nxt;
        bool p = 0;
        for(; i != last[pos]; i = i->nxt)
            if(i->expon < k){
                LIST *tmp = i->lst;
                i->lst = PU;
                PU->nxt = i;
                tmp->nxt = PU;
                PU->lst = tmp;
                p = 1;
                break;
            }
        if(!p){
            LIST *tmp = i->lst;
            i->lst = PU;
            PU->nxt = i;
            tmp->nxt = PU;
            PU->lst = tmp;
        }
    }
}
void print_ans(int pos){
    cout << (pos ? "mult = " : "add = ");
    for(LIST *i = ansST[pos]->nxt; i != ansED[pos]; i = i->nxt){
        cout << i->coef << (i->expon ? "x" : "");
        if(i->expon > 1) cout << (i->expon > 1 ? "^" : "") << i->expon;
        if(i->nxt != ansED[pos]) cout << " + ";
    }
    cout << endl;
}
void push_ans(int pos, float n, int k){
    LIST *now = ansST[pos]->nxt;
    bool p = 0;
    for(; now != ansED[pos]; now = now->nxt){
        if(now->expon == k){
            p = 1;
            now->coef += n;
        }
        if(now->expon < k) break;
    }
    if(!p){
        LIST *tmp = now->lst;
        LIST *PU = new LIST;
        PU->coef = n, PU->expon = k;

        PU->lst = tmp;
        tmp->nxt = PU;
        PU->nxt = now;
        now->lst = PU;
    }
}
void add(){
    LIST *A = root[0]->nxt;
    LIST *B = root[1]->nxt;
    while(A != last[0] && B != last[1]){
        if(A->expon == B->expon){
            push_ans(0, A->coef + B->coef, A->expon);
            A = A->nxt; B = B->nxt;
        }
        else if(A->expon < B->expon){
            push_ans(0, B->coef, B->expon);
            B = B->nxt;
        }
        else{
            push_ans(0, A->coef, A->expon);
            A = A->nxt;
        }
    }
    for(; A != last[0]; A = A->nxt)
        push_ans(0, A->coef, A->expon);
    for(; B != last[1]; B = B->nxt)
        push_ans(0, B->coef, B->expon);
}
void mul(){
    for(LIST *i = root[0]->nxt; i != last[0]; i = i->nxt){
        for(LIST *j = root[1]->nxt; j != last[1]; j = j->nxt)
            push_ans(1, i->coef * j->coef, i->expon + j->expon);
    }
}

int main(){
    init();

    float n;
    int k;
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
    add();
    print_ans(0);
    mul();
    print_ans(1);
}