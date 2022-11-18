#include "iostream"
#include "string"
#include "map"
#include "algorithm"
using namespace std;
#define xiaoyox

struct LIST{
    LIST *nxt, *lst;
    string s;
    int cnt;
    LIST(){
        cnt = 0;
    }
};

LIST *root = new LIST;
LIST *last = new LIST;
map<string, bool> st;

void push_back(string s){
    LIST *now = new LIST;
    now->s = s;
    now->cnt = 1;

    LIST *tmp = last->lst;
    now->nxt = last;
    now->lst = tmp;
    tmp->nxt = now;
    last->lst = now;
}
void push(int pos, string s){
    LIST *POS = root->nxt;
    for(int i = 0; i < pos; i++)
        POS = POS->nxt;
    
    LIST *now = new LIST;
    now->s = s;
    now->cnt = 1;

    now->nxt = POS;
    now->lst = POS->lst;
    LIST *tmp = POS->lst;
    POS->lst = now;
    tmp->nxt = now;
}
void init(){
    root->nxt = last;
    last->lst = root;
}
void print(){
    for(LIST *i = root->nxt; i != last; i = i->nxt)
        cout << i->s << ", " << i->cnt << endl;
}
string to_lower(string s){
    for(int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    return s;
}

int main(){
    #ifdef xiaoyo
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    
    init();
    string s;
    while(cin >> s){
        if(s == "#Finish") break;
        if(st.count(to_lower(s))){
            for(LIST *i = root->nxt; i != last; i = i->nxt){
                if(to_lower(i->s) == to_lower(s)) i->cnt++;
            }
        }
        else{
            push_back(s);
            st[to_lower(s)] = 1;
        }
    }
    int idx; string t;
    while(cin >> s){
        if(s == "#Print") print();
        else if(s == "#Insert"){
            cin >> idx >> t;
            if(st.count(to_lower(t))){
                for(LIST *i = root->nxt; i != last; i = i->nxt){
                    if(to_lower(i->s) == to_lower(t)) i->cnt++;
                }
            }
            else if(idx > st.size()) continue;
            else{
                push(idx, t);
                st[to_lower(t)] = 1;
            }
        }   
        else if(s == "#Add"){
            cin >> t;
            if(st.count(to_lower(t))){
                for(LIST *i = root->nxt; i != last; i = i->nxt){
                    if(to_lower(i->s) == to_lower(t)) i->cnt++;
                }
            }
            else{
                push_back(t);
                st[to_lower(t)] = 1;
            }
        }
        else if(s == "#Exit") break;
    }
}