#include "iostream"
#include "vector"
using namespace std;

vector<int> v[20];
int d[20];

int main(){
    string s, t;
    getline(cin, s);
    getline(cin, t);
    
    for(int i = 0; i < 20; i++) d[i] = -1;

    vector<int> ss, tt;
    for(int i = 0; i < s.length(); i++){
        if(!(s[i] >= '0' && s[i] <= '9')) continue;
        ss.push_back(s[i] - '0');
        d[s[i] - '0'] = 0;
    }
    for(int i = 0; i < t.length(); i++){
        if(!(t[i] >= '0' && t[i] <= '9')) continue;
        tt.push_back(t[i] - '0');
    }

    for(int i = 0; i < ss.size(); i++){
        for(int j = 0; j < tt.size(); j++){
            if(ss[i] == tt[j]){
                int k = j - 1;
                while(k >= 0){
                    if(d[tt[k]] < d[ss[i]]) break;
                    d[tt[k--]]++;
                }
                k = j + 1;
                while(k != tt.size()){
                    if(d[tt[k]] < d[ss[i]]) break;
                    d[tt[k++]]++;
                }
                break;
            }
        }
    }
    int MAX = 0;
    for(int i = 1; i < 20; i++){
        if(d[i] == -1) continue;
        v[d[i]].push_back(i);
        MAX = max(MAX, d[i]);
    }
    for(int i = 0; i <= MAX; i++){
        cout << i + 1 << ":";
        for(int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << (j == v[i].size() - 1 ? "" : ",");
        cout << endl;
    }
}