#include "iostream"
#include "stack"
using namespace std;

stack<char> st;

int main(){
    string s;
    while(cin >> s){
        if(s == "end") return 0;
        bool p = 1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')'){
                if(!st.empty() && st.top() == '(') st.pop();
                else{
                    cout << -1 << endl;
                    p = 0;
                    break;
                }
            }
        }
        if(!st.empty()){
            cout << -1 << endl;
            continue;
        }
        if(p) cout << 1 << endl;
    }
}