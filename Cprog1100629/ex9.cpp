#include "iostream"
#include "math.h"
using namespace std;
int main()
{
    int n;
    cin >> n;

    double arr[100][2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
    double k, ans, count1, a[2], b[2];
    count1 = INT64_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n && i != j; j++)
        {
            k = sqrt(pow((arr[i][0] - arr[j][0]), 2) + pow((arr[i][1] - arr[j][1]), 2));

            if (k < count1)
            {
                count1 = k;
                a[0] = arr[i][0];
                a[1] = arr[i][1];
                b[0] = arr[j][0];
                b[1] = arr[j][1];
            }
        }
    }
    if (sqrt(pow(a[0], 2) +pow(a[1],2)) > sqrt(pow(b[0],2) + pow(b[1],2))) {
       swap(a,b);
    }
    printf("(%4.2lf,%4.2lf),(%4.2lf,%4.2lf) ", a[0], a[1], b[0], b[1]);
    printf("distance=%4.2lf\n", count1);
}