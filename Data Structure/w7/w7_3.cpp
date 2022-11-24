#include "iostream"
#include "string"
#include "stack"
using namespace std;

int change(string s){
    int res = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9')
            res = res * 10 + (s[i] - '0');
        else{
            return -1;
        }
    }
    return res;
}

int main(){
    string s;
    stack<int> st;
    while(cin >> s){
        int now = change(s);
        if(now != -1) st.push(now);
        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(s == "+") st.push(b + a);
            else if(s == "-") st.push(b - a);
            else if(s == "*") st.push(b * a);
            else if(s == "/") st.push(b / a);
            else if(s == "%") st.push(b % a);
        }
    }
    cout << st.top() << endl;
}