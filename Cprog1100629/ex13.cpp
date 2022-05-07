#include "iostream"
using namespace std;
unsigned long long c(int, int);
int main()
{
    int n, k;
    unsigned long long int ans = 0;
    while (cin >> n >> k)
    {
        if (n < k)
            cout << "error" << endl;
        else
        {
            ans = c(n, k);
            cout << ans << endl;
        }
    }
}
unsigned long long c(int n, int k)
{
    unsigned long long u = 1, d = 1;
    for (int i = 0; i < k; i++)
    {
        u = u * (n - i);
        if (u%(k-i)==0) u=u/(k-i);
        else d = d * (k - i);
    }
    return u / d;
}