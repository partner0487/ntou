#include "iostream"
using namespace std;

bool check(int x){
    int a = x % 10;
    int b;
    while(x){
        if(x / 10 == 0) b = x; 
        x /= 10;
    }
    return (a == b);
}

int main(){
    int a, b;
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        if(check(i)) cout << i << " ";
    }
    cout << endl;
}