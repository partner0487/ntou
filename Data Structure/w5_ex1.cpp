#include "iostream"
#include "string"
#include "string.h"
#include "algorithm"
using namespace std;

struct trie{
    trie *nxt[26];
    int sz, cnt;
    trie() : sz(0), cnt(0){
        memset(nxt, 0, sizeof(nxt));
    }
};

trie *root = new trie();

void insert(string &s){
    trie *now = root;
    for(auto i : s){
        if(now->nxt[i - 'a'] == NULL)
            now->nxt[i - 'a'] = new trie();
        now->sz++;
        now = now->nxt[i - 'a'];
    }
    now->sz++;
    now->cnt++;
}
int prefix(string &s){
    trie *now = root;
    for(auto i : s){
        if(now->nxt[i - 'a'] == NULL) return 0;
        now = now->nxt[i - 'a'];
    }
    return now->sz;
}
int count(string &s){
    trie *now = root;
    for(auto i : s){
        if(now->nxt[i - 'a'] == NULL) return 0;
        now = now->nxt[i - 'a'];
    }
    return now->cnt;
}
void del(string &s){
    trie *now = root;
    for(auto i : s){
        now->sz--;
        now = now->nxt[i - 'a'];
    }
    now->sz--; now->cnt--;
}

int main(){
    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    int c, w;
    cin >> c >> w;
    string all;
    getchar();
    getline(cin, all);
    int st = 0, en = 0;
    for(int i = 0; i < all.length(); i++){
        if(all[i] == ' '){
            en = i;
            string ss = all.substr(st, en - st);
            cout << ss << endl;
            insert(ss);
            reverse(ss.begin(), ss.end());
            insert(ss);
            st = i + 1;
        }
    }
    cout << prefix(s) << " " << prefix(t) << endl;
}