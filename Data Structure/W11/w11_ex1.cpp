#include "iostream"
#include "string"
#include "algorithm"
#include "stack"
using namespace std;

int main(){
    string tree;
    getline(cin, tree);

    string v;
    while(getline(cin, v)){
        for(int i = 0; i < tree.length(); i++){
            if(tree[i] == '(' || tree[i] == ')' || tree[i] == ' ' || (tree[i] >= '0' && tree[i] <= '9')) continue;
            if(tree.substr(i, v.length() - 4) ==  v.substr(0, v.length() - 4)){
                tree.insert(i, v, v.length() - 1, v.length());
                int now = i + 1;
                for(int j = 0; j < v.length() - 4; j++)
                    tree.erase(now++, 1);
            }
        }
    }
    reverse(tree.begin(), tree.end());
    string post = "";
    for(int i = 0; i < tree.length(); i++)
        if(tree[i] != '(' && tree[i] != ')' && tree[i] != ' ') post += tree[i];
    stack<int> st;
    for(int i = 1; i < (int)post.length(); i++){ // etutor是拉基judge會讀到/r 所以i從1開始 正常情況要從0
        if(post[i] >= '0' && post[i] <= '9') st.push(post[i] - '0');
        else{
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            if(post[i] == '+') st.push(a + b);
            else if(post[i] == '-') st.push(a - b);
            else if(post[i] == '*') st.push(a * b);
            else if(post[i] == '/') st.push(a / b);
        }
    }
    cout << st.top() << endl;
}