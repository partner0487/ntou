#include "iostream"
using namespace std;

int a[1005];
bool vis[1005];
int n;

int check(int x){
    vis[x] = 1;
    for(int i = x - 1; i > 0; i--){
        if(!vis[i]) return i;
    }
    return 0;
}
void init(){
    for(int i = 1; i <= n; i++)
        vis[i] = 0;
}

int main(){
    cin >> n;
    while(cin >> a[0]){
        if(a[0] == -1) return 0;
        init();
        int now = check(a[0]);
        bool p = 1;
        for(int i = 1; i < n; i++){
            cin >> a[i];
            if(a[i] < now){
                p = 0;
                cout << "NO" << endl;
            }
            now = check(a[i]);
        }
        if(p)
            cout << "YES" << endl;
    }
}