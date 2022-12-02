#include "iostream"
#include "map"
#include "vector"
using namespace std;
#define xiaoyox

map<string, int> W;
map<int, string> V;

void pre(int x){
    if(V.count(x)){
        if(V[x] == "") return;
        cout << V[x] << " ";
        pre(2 * x);
        pre(2 * x + 1);
    }
}
void in(int x){
    if(V.count(x)){
        if(V[x] == "") return;
        in(2 * x);
        cout << V[x] << " ";
        in(2 * x + 1);
    }
}
void post(int x){
    if(V.count(x)){
        if(V[x] == "") return;
        post(2 * x);
        post(2 * x + 1);
        cout << V[x] << " ";
    }
}
int dfs(int x, int d = 0){
    if(V.count(x))
        return max(dfs(2 * x, d + 1), dfs(2 * x + 1, d + 1));
    return d;
}

int main(){
    #ifdef xiaoyo
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    string BT;
    while(getline(cin, BT) && BT[0] != '0'){
        string node[3];
        int cnt = 0;
        int st = 0;
        for(int i = 0; i < BT.length(); i++){
            if(BT[i] == ' ' || i == BT.length() - 1){
                node[cnt++] = BT.substr(st, i - st);
                st = i + 1;   // 有空再寫linkedList
            }
        }
        if(!(W.count(node[0]))){
            W[node[0]] = 1;
            V[W[node[0]]] = node[0];
            if((node[1][node[1].length() - 1] - '0') % 2){
                W[node[1]] = W[node[0]] * 2;
                W[node[2]] = W[node[0]] * 2 + 1;
            }
            else{
                W[node[1]] = W[node[0]] * 2 + 1;
                W[node[2]] = W[node[0]] * 2;
            }        
        }
        else{
            if((node[1][node[1].length() - 1] - '0') % 2){
                W[node[1]] = W[node[0]] * 2;
                W[node[2]] = W[node[0]] * 2 + 1;
            }
            else{
                W[node[1]] = W[node[0]] * 2 + 1;
                W[node[2]] = W[node[0]] * 2;
            }
        }
        V[W[node[1]]] = node[1];
        V[W[node[2]]] = node[2];
    }  
    //*
    cout << "Preorder: ";
    pre(1);
    cout << endl;
    cout << "Inorder: ";
    in(1);
    cout << endl;
    cout << "Postorder: ";
    post(1);
    cout << endl;//*/
    int l = dfs(2), r = dfs(3);
    cout << "The balance factor is " << abs(r - l) << endl;
}