#include "iostream"
#include "map"
#include "string"
#include "vector"
#include "string.h"
using namespace std;

int main(){
    string s, t;
    int c, w;
    cin >> s >> t >> c >> w;

    string all;
    getchar(); getchar();
    getline(cin, all);

    map<string, int> pre, suf, idx, CNT;
    int cnt = 1;
    int lowerCNT[26], upperCNT[26];
    int en = 0, st = 0;
    memset(lowerCNT, 0, sizeof(lowerCNT));
    memset(upperCNT, 0, sizeof(upperCNT));
    for(int i = 0; i < all.length(); i++){
        if(all[i] >= 'A' && all[i] <= 'Z') upperCNT[all[i] - 'A']++;
        else lowerCNT[all[i] - 'a']++;
        if(all[i] == ' ' || i == all.length() - 1){
            en = all[i] == ' ' ? i : i + 1;
            string ss = all.substr(st, en - st);
            CNT[ss]++;
            if(ss.substr(0, s.length()) == s) pre[ss]++;
            if(ss.substr(ss.length() - t.length(), t.length()) == t) suf[ss]++;
            st = i + 1;
        }
    }
    cout << "prefix of " << s << ":\n";
    for(auto i : pre)
        cout << i.first << endl;
    cout << "suffix of " << t << ":\n";
    for(auto i : suf)
        cout << i.first << endl;
    cout << "character frequency over " << c << ":\n";
    for(int i = 0; i < 26; i++)
        if(lowerCNT[i] >= c)
            cout << char(i + 'a') << "," << lowerCNT[i] << endl;
    for(int i = 0; i < 26; i++)
        if(upperCNT[i] >= c)
            cout << char(i + 'a') << "," << upperCNT << endl;
    cout << "word frequency over " << w << ":\n";

    for(auto i : CNT){
        if(i.second >= w) cout << i.first << "," << i.second << endl;
    }
}