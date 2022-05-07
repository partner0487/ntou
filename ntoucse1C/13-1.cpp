#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int n;
void print(int a[]){
    for (int i = 0; i < n - 1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int a[], int start, int end){
    int l = start + 1, r = end;
    while (l <= r){
        while (r > start && a[r] >= a[start])
            r--;
        while (l <= end && a[l] < a[start])
            l++;
        if (r > l)
            swap(&a[l++], &a[r--]);
    }
    swap(&a[start], &a[r]);
    return r;
}

void quick_sort(int a[], int start, int end){
    if (end - start > 0){
        int key = Partition(a, start, end);
        printf("data[%d]=%d\n", key, a[key]);
        quick_sort(a, start, key - 1);
        quick_sort(a, key + 1, end);
    }
    else if (end - start == 0)
        printf("data[%d]=%d\n", end, a[end]);
}

int main(){
    int t;
    scanf("%d", &t); 
    while (t--){
        int a[510] = {};
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        quick_sort(a, 0, n - 1);
        print(a);
        memset(a, 0, sizeof(a));
    }
}