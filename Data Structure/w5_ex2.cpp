#include <stdio.h>   
#include "algorithm"
#include "math.h"
#define xiaoyox
   
int cont = 1;   
int n, ncount, k;   
int all;
   
int tower(int n, char a, char b, char c, int npegs[], int (*pegs)[19]){   
    int a1 = a - 'A';   
    int b1 = b - 'A';   
    int c1 = c - 'A';   
       
    if(n == 1){  
   
        pegs[c1][npegs[c1]++] = pegs[a1][--npegs[a1]];   
        pegs[a1][npegs[a1]] = 0;   
        if(cont % 5 == 0 || cont == all){
            if(cont % 5 == 0 && cont != all) printf("After Moved %d Times:\n", cont);
            else printf("Total Moved %d Times:\n", all);
            for(int i = 0; i < 3; i++){   
                ncount = 0;   
                char c = 'A' + i;   
                printf("%c:", c);   
    
                for(int j = 0; j < k; j++){   
                    if(pegs[i][j] != 0){   
                        printf(" %d", pegs[i][j]); 
                        ncount++;   
                    }   
                }
                printf("\n");
            }   
            if(cont != all) printf("***********************************\n");
        }
        ++cont;   
   
    }else{   
        tower(n - 1, a, c, b, npegs, pegs);    
   
        pegs[c1][npegs[c1]++] = pegs[a1][--npegs[a1]];   
        pegs[a1][npegs[a1]] = 0;   
        if(cont % 5 == 0 || cont == all){
            if(cont % 5 == 0 && cont != all) printf("After Moved %d Times:\n", cont);
            else printf("Total Moved %d Times:\n", all);
            for(int i = 0; i < 3; i++){   
                //*   
                ncount = 0;   
                char c = 'A' + i;   
                printf("%c:", c);//*/   
    
                for(int j = 0; j < k; j++){   
                    if(pegs[i][j] != 0){   
                        printf(" %d", pegs[i][j]);  
                        ncount++;   
                    }   

                } 
                printf("\n");
            }  
            if(cont != all) printf("***********************************\n");  
        }
        ++cont;   
   
        tower(n - 1, b, a, c, npegs, pegs);   
    }   
    return 0;   
}   
   
int main(){   
    #ifdef xiaoyo   
        freopen("in.txt", "r", stdin);   
        freopen("out.txt", "w", stdout);   
    #endif   
   
    int t = 1, n;   
    // scanf("%d", &t);   
    while(t--){ 
        cont = 1; 
        scanf("%d", &n);   
        k = n;
        int pegs[3][19] = {0}; 
        for(int i = 0; i < n; i++){   
            pegs[0][i] = n - i;   
        }   
        int npegs[3] = {n, 0, 0};   

        all = pow(2, n) - 1;
        printf("Number of Discs: %d\n", n);
        printf("***********************************\n");
        printf("Initial State:\nA: ");   
        for(int i = 0; i < n; i++){
            printf("%d", pegs[0][i]);   
            if(i != n - 1) printf(" ");
        }
        // printf("\n");   
        printf("\nB:");   

        printf("\nC:");   
        printf("\n");   
        printf("***********************************\n");
   
        tower(n, 'A', 'B', 'C', npegs, pegs);
    }   
}