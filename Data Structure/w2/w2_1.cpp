#include "iostream"
using namespace std;

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sort(int num[], int n){
    for(int i = 0, min; i < n; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(num[j] < num[min])
                min = j;
        }
        Swap(num[i], num[min]);
    }
}

int main(){
    int n; cin >> n;

    int num[101];
    for(int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, n);
    for(int i = 0; i < n; i++){
        cout << num[i];
        cout << (i + 1 < n ? " " : "\n");
    }
}