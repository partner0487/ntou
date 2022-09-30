#include "iostream"
using namespace std;

int arr[20][20];

void build(int n, int now, int x, int y){
    arr[x][y] = now++;
    if(now == n * n + 1) return;
    int nxtx = x - 1, nxty = y + 1;
    nxty %= n; nxtx = (nxtx + n) % n;
    if(arr[nxtx][nxty]) nxtx = x + 1, nxty = y;
    // cout << nxtx << " " << nxty << endl;
    build(n, now, nxtx, nxty);
}

int main(){
    int n; cin >> n;

    build(n, 1, 0, n / 2);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << arr[i][j] << (j == n - 1 ? "" : " ");
        cout << endl;
    }
}