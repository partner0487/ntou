#include "iostream"
using namespace std;

struct tree{
    int v;
    tree *l, *r;
    tree(){
        l = NULL, r = NULL;
    }
};

void insert(tree *&now, int n){
    if(now == NULL){
        now = new tree;
        now->v = n;
        return;
    }
    if(n > now->v) insert(now->r, n);
    else           insert(now->l, n);
}

int dfs(tree *now, int d){
    if(now != NULL){
        int l = dfs(now->l, d + 1);
        int r = dfs(now->r, d + 1);
        return max(l, r);
    }
    return d;
}

int main(){
    int n;
    tree *root = NULL;
    while(cin >> n) insert(root,n);
    cout << dfs(root, 0) << endl;
}