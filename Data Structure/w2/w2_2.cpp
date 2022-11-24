#include "iostream"
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int num[105];
    for(int i = 0; i < k; i++) cin >> num[i];

    int l = 0, r = n - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(num[mid] < n)
            l = mid + 1;
        else if(num[mid] > n)
            r = mid - 1;
        else break;
    }
    cout << (l + r >> 1) << endl;
}