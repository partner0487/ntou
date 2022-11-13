#include "iostream"
#include "climits"
#define xiaoyo
using namespace std;

struct node{
    int num;
    node *nxt;
};

node *root = new node;
int last = 0;

void insert(int n, int pos, node *&root){
    node *tmp;
    node *New = new node;
    New->num = n;
    if(pos < 0) pos = 0;
    else if(pos > last) pos = INT_MAX;
    if(pos == 0){
        tmp = (root->nxt ? root->nxt : NULL);
        New->nxt = tmp;
        root->nxt = New;
        last++;
    }
    else if(pos == INT_MAX){
        node *now = root;
        for(int cnt = -1; cnt < last - 1; cnt++)
            now = now->nxt;
        now->nxt = New;
        last++;
    }
    else{
        node *now = root->nxt;
        for(int cnt = 0; cnt < pos - 1; cnt++)
            now = now->nxt;
        New->nxt = now->nxt;
        now->nxt = New;
        last++;
    }
}
void print(node *root){
    cout << "Created Linked list is:  ";
    node *now = root->nxt;
    for(int i = 0; i < last; i++){
        cout << now->num << (i == last - 1 ? " " : "  ");
        now = now->nxt;
    }
    cout << endl;
}

int main(){
    #ifdef xiaoyox
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t; cin >> t;
    char op; int n, pos;
    while(t--){
        node *root = new node;
        last = 0;
        while(cin >> op){
            if(op != 'f' && op != 'i' && op != 'a'){
                cout << (t ? "\n" : "");
                break;
            }
            else if(op == 'f'){
                cin >> n;
                insert(n, 0, root);
            }
            else if(op == 'i'){
                cin >> n >> pos;
                insert(n, pos, root);
            }
            else if(op == 'a'){
                cin >> n;
                insert(n, INT_MAX, root);
            }
            print(root);
        }
        delete root;
    }
}