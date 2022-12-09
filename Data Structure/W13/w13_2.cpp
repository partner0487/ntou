#include "iostream"
using namespace std;

struct node{
    int v;
    node *l, *r;
    node(){
        l = NULL, r = NULL;
    }
};

void insert(node *&now, int v){
    if(!now){
        now = new node;
        now->v = v;
        return;
    }
    if(v < now->v) insert(now->l, v);
    else           insert(now->r, v);
}

void print(node *now){
    if(now){
        cout << now->v << " ";
        print(now->l);
        print(now->r);
    }
}

int dfs(node *&now, int t){
    if(t){
        if(now->l == NULL){
            int ret = now->v;
            now = now->r;
            return ret;
        }
    }
    else{
        if(now->r == NULL){
            int ret = now->v;
            now = now->l;
            return ret;
        }
    }
    return t ? dfs(now->l, t) : dfs(now->r, t);
}

int remove(node *&now, int v){
    if(now == NULL) return 0;
    if(v < now->v) remove(now->l, v);
    else if(v > now->v) remove(now->r, v);
    else{
        if(now->l == NULL && now->r == NULL)
            now = NULL;
        else
            now->v = now->l == NULL ? dfs(now->r, 1) : dfs(now->l, 0);
    }
    return 1;
}

int main(){
    node *root = NULL;
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int num[100];
    for(int i = 0; i < 100; i++) 
        num[i] = 0;
    int cnt = 0;
    int now = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ' || i == s.length() - 1){
            num[cnt++] = now;
            now = 0;
            continue;
        }
        else{
            now = now * 10 + (s[i] - '0');
            // if(i == s.length() - 1)
                // num[cnt++] = now;
        }
    }
    bool check[1000];
    for(int i = 0; i < 1000; i++) check[i] = 0;
    for(int i = 0; i < cnt; i++){
        check[num[i]] = 1;
        insert(root, num[i]);
    }
    cout << "Binary search tree (before):" << endl;
    print(root);
    cout << endl;

    int del[100];
    for(int i = 0; i < 100; i++)
        del[i] = 0;
    cnt = 0;
    now = 0;
    for(int i = 0; i < t.length(); i++){
        if(t[i] == ' '){
            del[cnt++] = now;
            now = 0;
            continue;
        }
        else{
            now = now * 10 + (t[i] - '0');
            if(i == t.length() - 1)
                del[cnt++] = now;
        }
    }
    for(int i = 0; i < cnt; i++){
        if(check[del[i]]){
            remove(root, del[i]);
        }
        else{
            cout << "no " << del[i] << endl;
        }
    }
    cout << "Binary search tree (after):" << endl;
    print(root);
    cout << endl;
}