/*邪教寫法 抄我的100%被老師發現 請三思*/
#include "iostream"
#include "vector"
using namespace std;

int n;
vector<bool> ep;
int ed, st;

void FindST(){
    for(int i = ed - 1; i >= 0; i--){
        if(!ep[i]){
            st = i + 1;
            return;
        }
    }
    st = 0;
}

void Move(int ed, int st){
    if(ep[ed + 2] || ed + 1 == n) return;
    ep[ed + 1] = 1, ep[st] = 0;
    st += 1, ed += 1;
    Move(ed, st);
}

int main(){
    cin >> n;
    ep.clear(); ep.resize(n); 
    vector<vector<bool> > all;
    int se;
    int now = 0;
    while(cin >> se){
        for(int i = now; i < now + se; i++)
            ep[i] = 1;
        now = now + se + 1;
    }
    all.push_back(ep);
    ed = 0, st = n - 1;
    for(int i = max(st, 0); i >= 0; i--){
        if(ep[i]){
            ed = i;
            FindST();
            Move(ed, st);
        }
        all.push_back(ep);
    }
    for(int i = 0; i < n; i++){
        bool p = 1;
        for(int j = 0; j < all.size(); j++)
            if(!all[j][i]) p = 0;
        cout << p << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}