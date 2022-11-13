#include "iostream"
#include "map"
#include "string"
#include "utility"
#define xiaoyo
using namespace std;

int main(){
    #ifdef xiaoyox
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n; cin >> n;

    int m[105];
    for(int i = 0; i < n; i++) cin >> m[i];

    
    map<string, int> mp;
    for(int i = 0; i < n; i++){
        string s;
        for(int j = 0; j < m[i]; j++){
            cin >> s;
            mp[s]++;
        }
        int cnt = 0;
        for(auto j : mp){
            cnt += j.second % 2;
        }
        cout << cnt << endl;
        mp.clear();
    }
}