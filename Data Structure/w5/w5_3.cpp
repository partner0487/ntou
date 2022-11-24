#include "string"
#include "iostream"
using namespace std;

void H(int a[][25], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n / 2; j++)
            swap(a[i][j], a[i][n - 1 - j]);
    }
}
void V(int a[][25], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n / 2; j++)
            swap(a[j][i], a[n - 1 - j][i]);
    }
}
void D(int a[][25], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++)
            swap(a[i][j], a[j][i]);
    }
}
void debug(int a[][25], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    
    int arr[25][25];
    char s[20];
    //*
    string s;

    int now = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            arr[i][j] = now++;
    }

    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'H') H(arr, n);
        else if(s[i] == 'V') V(arr, n);
        else D(arr, n);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << arr[i][j] << (j == n - 1 ? "" : " ");
        cout << endl;
    }//*/
}