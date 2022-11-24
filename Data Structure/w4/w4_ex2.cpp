#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

void solve(string &s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a') reverse(s.begin() + i + 1, s.end());
        if(s[i] == 'b'){
            string ss = s.substr(i + 1, s.length());
            s += ss;
        }
        if(s[i] == 'c'){
            if(i != s.length() - 1){
                s.erase(i + 1, 2);
            }
        }
    }
}

int main(){
    int n; cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        solve(s);
        cout << s << endl;
    }
}