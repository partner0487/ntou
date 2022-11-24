#include "iostream"
#include "algorithm"
using namespace std;

int idx[100000];
int value[100000];

int main(){
    int n;
    cin >> n;
    int F, l, r;
    bool p = 0;
    int MAX = 0;
    while(cin >> F){
        if(F == -1) break;
        cin >> l >> r;
        if(!p){
            idx[F] = 1;
            value[idx[F]] = F;
            p = 1;
        }
        idx[l] = 2 * idx[F];
        idx[r] = 2 * idx[F] + 1;
        value[idx[l]] = l;
        value[idx[r]] = r;
        MAX = max(MAX, idx[r]);
    }
    for(int i = 1; i <= MAX; i++)
        cout << value[i] << (i == MAX ? "" : " ");
    cout << endl;
}