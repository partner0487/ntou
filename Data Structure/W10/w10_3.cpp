#include "iostream"
#include "map"
#include "string"
using namespace std;

typedef long long ll;

struct LIST{
    LIST *nxt, *lst;
    int k;
};
LIST *ListST[1005];
LIST *ListED[1005];
int n;

void init(){
    for(int i = 0; i < n; i++){
        ListST[i] = new LIST;
        ListED[i] = new LIST;
        ListST[i]->nxt = ListED[i];
        ListED[i]->lst = ListST[i];
    }
}
void push(int pos, int k){
    LIST *now = new LIST;
    now->k = k;
    bool p = 0;
    for(LIST *i = ListST[pos]->nxt; i != ListED[pos]; i = i->nxt){
        if(i->k > k){
            LIST *tmp = i->lst;
            now->nxt = i;
            now->lst = tmp;
            tmp->nxt = now;
            i->lst = now;
            p = 1;
            break;
        }
    }
    if(!p){
        LIST *tmp = ListED[pos]->lst;
        now->nxt = ListED[pos];
        now->lst = tmp;
        tmp->nxt = now;
        ListED[pos]->lst = now;
    }
}
map<int, string> m;
map<string, int> mm;

int main(){
    cin >> n;
    init();
    string s;
    int idx = 0;
    for(int i = 0, k; i < n; i++){
        cin >> s >> k;
        if(!mm.count(s)) mm[s] = idx;
        m[idx] = s;
        push(mm[s], k);
        idx++;
    }
    for(int i = 0; i < n; i++){
        if(mm[m[i]] == i){
            cout << m[i] << ",";
            for(LIST *j = ListST[i]->nxt; j != ListED[i]; j = j->nxt)
                cout << j->k << ",";
            cout << endl;
        }
    }
}