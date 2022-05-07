#include <stdio.h>  
#include <stdlib.h>  
#define larger 2000000000    
#define max 2000005    
#define ll long long  
  
static int state = 0;  
  
void set(int seed){  
    state = seed;  
}  
  
int next(){  
    state = (state * 0x343FD + 0x269EC3) & 0x7FFFFFFF;  
    return state >> 15; // maximum is 65535, minimum is 0  
}  
  
struct Sample{  
    int label;  
    double score;  
};  
  
struct Sample *prepare(int n, int iseed){  
    int i;  
    set(iseed);  
    struct Sample *ptr = (struct Sample *) malloc(2 * n * sizeof(struct Sample));  
    if (ptr == NULL) return NULL;  
    for (i = 0; i < 2 * n; i++)  
        ptr[i].label = i < n,  
        ptr[i].score = next()/65535.0*0.7 + 0.3 * (1 - ptr[i].label);  
    return ptr;  
}  
  
Sample L[max / 2 + 2], R[max / 2 + 2];   
  
void merge(Sample A[], int n, int left, int mid, int right){    
    int n1 = mid - left;     
    int n2 = right - mid;    
    for(int i = 0; i < n1; i++){  
        L[i].score = A[left + i].score;  
        L[i].label = A[left + i].label;  
    }     
    for(int i = 0; i < n2; i++){     
        R[i].score = A[mid + i].score;    
        R[i].label = A[mid + i].label;  
    }  
  
    L[n1].score = R[n2].score = larger;    
        
    int i = 0, j = 0;    
    for(int k = left; k < right; k++){    
        if(L[i].score <= R[j].score){    
            A[k].score = L[i].score;    
            A[k].label = L[i++].label;  
        }
        else{    
            A[k].score = R[j].score;   
            A[k].label = R[j++].label;   
        }    
    }    
}    
//*
void MGS(Sample A[], int n, int left, int right){    
    int mid;        
    if(left + 1 < right){    
        mid = (left + right) / 2;    
        MGS(A, n, left, mid);    
        MGS(A, n, mid, right);    
        merge(A, n, left, mid, right);      
    }  
}  //*/
  
int main(){  
    int n, iseed;  
    while(scanf("%d %d", &n, &iseed) != EOF){  
        Sample *ptr = prepare(n, iseed);  
        MGS(ptr, 2 * n, 0, 2 * n);   
        //*  
        int cnt1 = 0; 
        ll cnt = 0; 
        for(int i = 2 * n - 1; i >= 0; i--){  
            if(ptr[i].label == 1) cnt1++;  
            else cnt += (n - cnt1);  
        }  
        printf("%lld\n", cnt);//*/  
    }  
}