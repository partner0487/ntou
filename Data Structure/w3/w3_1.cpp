#include "iostream"
using namespace std;

int main(){
    int n; cin >> n;
    int l[5000];

    for(int i = 0; i < n; i++) cin >> l[i];

    int MXN = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 2; j < n; j++)
            MXN = max(MXN, l[i] + l[j]);
    }
    cout << MXN << endl;
}