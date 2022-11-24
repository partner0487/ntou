#include "iostream"
#include "algorithm"
#include "string"
#include "iomanip"
#define ll long long
using namespace std;

const long long p = 75577;
const long long mod = 998244353;
long long Hash[200000], Hash_reverse[200000];

ll Pow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void build(string s){
    ll val = 0;
    for(int i = 0; i < s.length(); i++){
        val = (val * p + s[i]) % mod;
        Hash[i + 1] = val;
    }
}
void build_reverse(string s){
    reverse(s.begin(), s.end());
    ll val = 0;
    for(int i = 0; i < s.length(); i++){
        val = (val * p + s[i]) % mod;
        Hash_reverse[i + 1] = val;
    }
}
ll Get(int i, int j){
    return (Hash[j + 1] - Hash[i] * Pow(p, j - i + 1) % mod + mod) % mod;
}
ll Get_reverse(int i, int j){
    return (Hash_reverse[j + 1] - Hash_reverse[i] * Pow(p, j - i + 1) % mod + mod) % mod;
}

int main(){
    string s;
    cin >> s;
    build(s); build_reverse(s);

    int n = (int)s.length();

    int MAX = 0;
    int x, y;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(Get(i, j) == Get_reverse(n - j - 1, n - i - 1)){
                // cout << i << " " << j << endl;
                // cout << Get(i, j) << " " << Get_reverse(i, j) << endl;
                if(j - i + 1 > MAX){
                    MAX = j - i + 1;
                    x = i, y = j;
                }
            }
        }
    }
    for(int i = x; i <= y; i++) cout << s[i];
    cout << endl;
}