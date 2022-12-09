#include "iostream"
#include "vector"
using namespace std;

int DSU[1000];

void init(int x){
    for(int i = 0; i < x; i++)
        DSU[i] = i;
}
int find(int x){
    if(DSU[x] == x) return x;
    return DSU[x] = find(DSU[x]);
}
void merge(int x, int y){
    x = find(x), y = find(y);
    DSU[y] = (x == y ? DSU[y] : x);
}
void check(int x){
    vector<int> v[x];
    for(int i = 0; i < x; i++){
        int tmp = i;
        tmp = find(tmp);
        v[DSU[tmp]].push_back(i);
    }
    for(int i = 0; i < x; i++){
        if(v[i].size()){
            cout << " {";
            for(int j = 0; j < v[i].size(); j++)
                cout << v[i][j] << (j == v[i].size() - 1 ? "" : ",");
            cout << "}";
        }
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    init(n);
    getchar();
    getchar();
    string s;
    while(getline(cin, s)){
        if(s[0] == '-' && s[1] == '1') break;
        s.pop_back();
        cout << s << ":";
        if(s.substr(0, 5) == "Union"){
            int now = 0;
            int x = 0, y = 0;
            for(int i = 5; i < s.length(); i++){
                if(s[i] >= '0' && s[i] <= '9')
                    now = now * 10 + (s[i] - '0');
                else{
                    x ? y = now : x = now;
                    now = 0;
                }
            }
            if(x > y) swap(x, y);
            merge(x, y);
            check(n);
        }
        else if(s.substr(0, 4) == "Find"){
            int now = 0;
            int x = 0, y = 0;
            for(int i = 5; i < s.length(); i++){
                if(s[i] >= '0' && s[i] <= '9')
                    now = now * 10 + (s[i] - '0');
                else{
                    x ? y = now : x = now;
                    now = 0;
                }
            }
            cout << (DSU[x] == DSU[y] ? " Yes" : " No") << endl;
        }
    }
}