#include "iostream"
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int ar[50];
    for(int i = 0; i < n; i++){
        int now = i;
        for(int j = i + 1; j <= n; j++)
            now = (now + b) % j;
        ar[i] = now;
    }
    for(int i = n - 1; i >= 0; i--)
        cout << (ar[i] + a - 1) % n + 1 << (i == 0 ? "" : " ");
    cout << endl;
}