#include "iostream"
#include "vector"
using namespace std;

struct node{
    int n;
    node *l, *r;
    node(){
        l = NULL; r = NULL;
    }
};
vector<int> v1, v2, v3;
void insert(int n, node *&now){
    if(!now){
        now = new node;
        now->n = n;
        return;
    }
    if(n > now->n) insert(n, now->r);
    else           insert(n, now->l); 
}

void pre(node *now){
    if(now){
        v1.push_back(now->n);
        pre(now->l);
        pre(now->r);
    }
}
void in(node *now){
    if(now){
        in(now->l);
        v2.push_back(now->n);
        in(now->r);
    }
}
void post(node *now){
    if(now){
        post(now->l);
        post(now->r);
        v3.push_back(now->n);
    }
}

int main(){
    int n;
    node *tree = NULL;
    vector<int> N;
    while(cin >> n) N.push_back(n);

    for(int i = 0; i < N.size() - 1; i++)
        insert(N[i], tree);

    in(tree);
    pre(tree);
    post(tree);
    for(int i = 0; i < v2.size(); i++)
        if(v2[i] == N.back())
            cout << v2[i + 1] << " ";
    for(int i = 0; i < v1.size(); i++)
        if(v1[i] == N.back())
            cout << v1[i + 1] << " ";
    for(int i = 0; i < v3.size(); i++)
        if(v3[i] == N.back())
            cout << v3[i + 1] << endl;
}