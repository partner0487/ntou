#include <stdio.h>   
   
int n;  
   
int tower(int n, char a, char b, char c){   
    if(n == 1){   
        printf("%d", n);  
        printf("\n");   
   
    }else{   
        tower(n - 1, a, c, b);   
        printf("%d", n);   
        printf("\n");
   
        tower(n - 1, b, a, c);   
    }   
    return 0;   
}   
   
int main(){ 
    int t = 1, n;   
    // scanf("%d", &t);   
    while(t--){ 
        scanf("%d", &n);
   
        tower(n, 'A', 'B', 'C');
    }   
}