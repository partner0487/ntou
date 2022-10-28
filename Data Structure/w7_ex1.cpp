#include "iostream"
#include "stack"
using namespace std;

void Post(string s){
    stack<int> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9')
            st.push(s[i] - '0');
        else{
            int a = st.top();
            st.pop();
            if(!st.empty()){
                int b = st.top();
                st.pop();
                cout << "(" << b << s[i] << a << ")";
            }
            else{
                cout << s[i] << a;
            }
            /*
            if(s[i] == '+') st.push(b + a);
            else if(s[i] == '-') st.push(b - a);
            else if(s[i] == '*') st.push(b * a);
            else if(s[i] == '/') st.push(b / a);
            else if(s[i] == '%') st.push(b % a);//*/
        }
    }
}
void Pre(string s){
    stack<int> st;
    for(int i = s.length() - 1; i >= 0; i--){
        if(s[i] >= '0' && s[i] <= '9')
            st.push(s[i] - '0');
        else{
            int a = st.top();
            st.pop();
            if(!st.empty()){
                int b = st.top();
                st.pop();
                cout << "(" << a << s[i] << b << ")";
            }
            else{
                cout << s[i] << a;
            }
            /*
            if(s[i] == '+') st.push(b + a);
            else if(s[i] == '-') st.push(b - a);
            else if(s[i] == '*') st.push(b * a);
            else if(s[i] == '/') st.push(b / a);
            else if(s[i] == '%') st.push(b % a);//*/
        }
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