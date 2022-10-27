#include "iostream"
#include "stdio.h"
#include "map"
#include "utility"
#include "string"
#include "stack"
#include "queue"
#include "string.h"
using namespace std;

map<char, pair<int, int> > m;

void init(){
    m['('] = {0, 20};
    m['+'] = {12, 12};
    m['-'] = {12, 12};
    m['*'] = {13, 13};
    m['/'] = {13, 13};
    m['%'] = {13, 13};
}

int main(){
    init();
    int n;
    cin >> n; 
    cin.ignore();
    cin.ignore();
    string s;
    stack<char> st;

    while(n--){
        queue<char> q;
        getline(cin, s);
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9') q.push(s[i]);
            else if(s[i] == ' ') continue;
            else if(st.empty()) st.push(s[i]);
            else{
                if(s[i] == ')'){
                    while(st.top() != '('){
                        q.push(st.top());
                        st.pop();
                    }
                    st.pop();
                }
                else{
                    char now = st.top();
                    while(m[now].first >= m[s[i]].second && !st.empty()){
                        q.push(now);
                        st.pop();
                        if(!st.empty())
                            now = st.top();
                    }
                    st.push(s[i]);
                }
            }
        }  
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        while(!q.empty()){
            cout << q.front();
            q.pop();
            if(n > 0){
                cout << (q.size() - 1 ? " " : "");
                if(q.size() - 1 == 0) break;
            }
            else
                cout << (q.size() ? " " : "");
        }
        cout << '\n';  
    }
}