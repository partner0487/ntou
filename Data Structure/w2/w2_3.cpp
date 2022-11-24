#include "iostream"
using namespace std;

void insort(int arr[], int n){
    for(int i = 1, key, j; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int n; cin >> n;
    int arr1[10000];
    int arr2[2], arr3[3];

    for(int i = 0; i < n; i++)
        cin >> arr1[i];
    arr2[0] = arr3[0] = arr1[0]; arr2[1] = arr3[1] = arr1[1];
    arr3[2] = arr1[2];

    insort(arr1, n);
    insort(arr2, 2);
    insort(arr3, 3);
    for(int i = 0; i < 2; i++)
        cout << arr2[i] << (i < 1 ? " " : "\n");
    for(int i = 0; i < 3; i++)
        cout << arr3[i] << (i < 2 ? " " : "\n");
    for(int i = 0; i < n; i++)
        cout << arr1[i] << (i < n - 1 ? " " : "\n");
}