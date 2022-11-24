#include "iostream"
#include "string"
#include "string.h"
#include "algorithm"
#include "vector"
#include "map"
using namespace std;

struct trie{
    trie *lower[26];
    trie *upper[26];
    int sz, cnt;
    trie() : sz(0), cnt(0){
        memset(lower, 0, sizeof(lower));
        memset(upper, 0, sizeof(upper));
    }
};

int upperCnt[26], lowerCnt[26];
map<string, int> idx, CNT;
trie *root = new trie();

void insert(string &s){
    trie *now = root;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            upperCnt[s[i] - 'A']++;
            if(now->upper[s[i] - 'A'] == NULL)
                now->upper[s[i] - 'A'] = new trie();
            now->sz++;
            now = now->upper[s[i] - 'A'];
        }
        else{
            lowerCnt[s[i] - 'a']++;
            if(now->lower[s[i] - 'a'] == NULL)
                now->lower[s[i] - 'a'] = new trie();
            now->sz++;
            now = now->lower[s[i] - 'a'];
        }
    }
    now->sz++;
    now->cnt++;
}
vector<string> prefix(string &s){
    trie *now = root;
    vector<string> ret;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            if(now->upper[s[i] - 'A'] == NULL) return ret;
            now = now->upper[s[i] - 'A'];
        }
        else{
            if(now->lower[s[i] - 'a'] == NULL) return ret;
            now = now->lower[s[i] - 'a'];
        }
    }
    int cnt = 0;
    int to = now->sz;
    while(cnt < to){
        trie *tmp = now;
        string res = s;
        for(int i = 0; i < 26; i++){
            if(tmp->cnt){
                if(tmp->cnt == -1) continue;
                cnt += tmp->cnt;
                tmp->cnt = -1;
                ret.push_back(res);
                continue;
            }
            if((tmp->lower[i] && tmp->lower[i]->sz) || (tmp->upper[i] && tmp->upper[i]->sz)){
                if(tmp->lower[i]){
                    tmp->sz--;
                    tmp = tmp->lower[i];
                    res += i + 'a';
                }
                else{
                    tmp->sz--;
                    tmp = tmp->upper[i];
                    res += i + 'A';
                }
                i = -1;
            }
        }
    }
    return ret;
}

bool cmp(string a, string b){
    return idx[a] < idx[b];
}

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string s, t; 
    int c, w;
    cin >> s >> t >> c >> w;

    string tt = t;
    reverse(t.begin(), t.end());
    
    string all;
    getchar(); getchar();
    getline(cin, all);

    int st = 0, en = 0, cnt = 1;
    for(int i = 0; i < all.length(); i++){
        if(all[i] == ' ' || i == all.length() - 1){
            en = all[i] == ' ' ? i : i + 1;
            string ss = all.substr(st, en - st);
            idx[ss] = cnt++, CNT[ss]++;
            // cout << ss << endl;
            insert(ss);
            reverse(ss.begin(), ss.end());
            insert(ss);
            st = i + 1;
        }
    }
    vector<string> pre = prefix(s);
    vector<string> suf = prefix(t);
    for(int i = 0; i < suf.size(); i++)
        reverse(suf[i].begin(), suf[i].end());

    sort(pre.begin(), pre.end(), cmp);
    cout << "prefix of " << s << ":\n";
    for(int i = 0; i < pre.size(); i++)
        cout << pre[i] << endl;

    sort(suf.begin(), suf.end(), cmp);
    cout << "suffix of " << tt << ":\n";
    for(int i = 0; i < suf.size(); i++)
        cout << suf[i] << endl;

    cout << "character frequency over " << c << ":\n";
    for(int i = 0; i < 26; i++)
        if(lowerCnt[i] / 2 >= c) cout << char(i + 'a') << "," << lowerCnt[i] / 2 << endl;
    for(int i = 0; i < 26; i++)
        if(upperCnt[i] / 2 >= c) cout << char(i + 'A') << "," << upperCnt[i] / 2 << endl;
    
    cout << "word frequency over " << w << ":\n";
    
    vector<pair<string, int> > vec;
    for(pair<string, int> i : CNT)
        vec.push_back(i);
    
    sort(vec.begin(), vec.end());
    for(pair<string, int> i : vec)
        if(i.second >= w)
            cout << i.first << "," << i.second << endl;
}