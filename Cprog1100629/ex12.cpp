#include <iostream>
using namespace std;
int a[10][10], b[10][10];
void rotate(int r, int c)
{
    for (int i = c - 1; i >= 0; i--)
    {
        for (int j = 0; j < r; j++)
        {
            b[(c - 1) - i][j] = a[j][i];
        }
    }
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
void flip(int r, int c)
{
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = 0; j < c; j++)
        {
            b[(r - 1) - i][j] = a[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
int main()
{
    int op[10], r, c, m;
    while (cin >> r >> c >> m)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < m; i++)
            cin >> op[i];
        for (int i = m - 1; i >= 0; i--)
        {
            if (op[i] == 1)
            {
                flip(r, c);
            }
            else
            {
                rotate(r, c);
                swap(r, c);
            }
        }
        cout << r << " " << c << endl;
        for (int i = 0; i < r; i++)
        {
            cout << a[i][0];
            for (int j = 1; j < c; j++)
            {
                cout << " " << a[i][j];
            }
            cout << endl;
        }
    }
}