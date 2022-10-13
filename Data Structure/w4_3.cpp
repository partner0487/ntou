#include "iostream"
#include "iomanip"
using namespace std;

struct all{
    int i, j;
    int v;
}ALL[105];

int main(){
    int m, n;
    cin >> m >> n;
    int arr[105][105];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    int cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j]){
                ALL[cnt].i = i, ALL[cnt].j = j;
                ALL[cnt++].v = arr[i][j];
            }
        }
    }
    cout << m << " " << n << " " << cnt << endl;
    for(int i = 0; i < cnt; i++) cout << ALL[i].i << " " << ALL[i].j << " " << ALL[i].v << endl;
}