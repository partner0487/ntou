#include "iostream"
#include "stack"
using namespace std;

void Post(string s){
    stack<string> st;
    for(int i = 0; i < s.length(); i++){
        string t = s.substr(i, 1);
        if(s[i] >= '0' && s[i] <= '9')
            st.push(t);
        else{
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string now;
            if(i != s.length() - 1)
                now = "(" + b + s[i] + a + ")";
            else now = b + s[i] + a;
            st.push(now);
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}
void Pre(string s){
    stack<string> st;
    for(int i = s.length() - 1; i >= 0; i--){
        string t = s.substr(i, 1);
        if(s[i] >= '0' && s[i] <= '9') st.push(t);
        else{
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string now;
            if(i == 0) 
                now = a + s[i] + b;
            else now = "(" + a + s[i] + b + ")";
            st.push(now);
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}

int main(){
    string s;
    while(cin >> s){
        if(s[0] >= '0' && s[0] <= '9' && s[s.length() - 1] >= '0' && s[s.length() - 1] <= '9'){
            cout << "same" << endl;
            continue;
        }
        else if(s[0] >= '0' && s[0] <= '9'){
            Post(s);
            cout << endl;
        }
        else if(s[s.length() - 1] >= '0' && s[s.length() - 1] <= '9'){
            Pre(s);
            cout << endl;
        }
    }
}