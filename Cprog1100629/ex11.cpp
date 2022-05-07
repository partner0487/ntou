#include "iostream"
#include "algorithm"
using namespace std;

int state = 0;
void set(int x)
{
    state = x;
}
int next()
{
    state = (state * 0x343FD + 0x269EC3) & 0x7FFFFFFF;
    return (state >> 9) + 1;
}
int main()
{
    int seed, n, data[100000] = {};
    while (cin >> n)
    {
        cin >> seed;
        set(seed);
        for (int i = 0; i < n; i++)
        {
            data[i] = next();
        }
        sort(data, data + n);
        bool ans = 0;
        for (int i = n - 1; i >= 2; i--)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                for (int l = j - 1; l >= 0; l--)
                {
                    if (data[i] < data[j] + data[l])
                    {
                        cout << data[l] << " " << data[j] << " " << data[i] << endl;
                        ans = 1;
                        break;
                    }
                }
                if (ans)
                    break;
            }
            if (ans)
                break;
        }
        if (!ans)
            cout << "-1" << endl;
    }
}