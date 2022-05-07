#include <stdio.h>   
#define xiaoyox
   
int cont = 1;   
int n, ncount, k;   
   
   
int tower(int n, char a, char b, char c, int npegs[], int (*pegs)[19]){   
    int a1 = a - 'A';   
    int b1 = b - 'A';   
    int c1 = c - 'A';   
       
    if(n == 1){   
        printf("%5d: disk %d, peg-%c -> peg-%c> ", cont, n, a, c);   
   
        pegs[c1][npegs[c1]++] = pegs[a1][--npegs[a1]];   
        pegs[a1][npegs[a1]] = 0;   
   
        for(int i = 0; i < 3; i++){   
            ncount = 0;   
            char c = 'A' + i;   
            printf("%c:", c);   
   
            for(int j = 0; j < k; j++){   
                if(pegs[i][j] != 0){   
                    printf("%d ", pegs[i][j]);   
                    ncount++;   
                }   
            }  
            for(int i = 0; i < 2 * (k - ncount); i++) printf(" ");
            /* 
            if(c == 'A' || c == 'C'){   
                for(int i = 0; i < 2 * (k - ncount); i++) printf(" ");   
            }else{   
                for(int i = 0; i < 2 * (k - ncount) - 2; i++) printf(" "); 
                if(2 * k - 2 < ){ 
                    for(int i = 0; i < 4 - (2 * k - 2); i++){ 
                        printf(" "); 
                    } 
                } 
                // if(4 - (2 * (k - ncount) - 2) > 0) printf(" ");   
            } //*/  
        }   
        printf("\n");   
        ++cont;   
   
    }else{   
        tower(n - 1, a, c, b, npegs, pegs);   
        printf("%5d: disk %d, peg-%c -> peg-%c> ", cont, n,  a, c);   
   
        pegs[c1][npegs[c1]++] = pegs[a1][--npegs[a1]];   
        pegs[a1][npegs[a1]] = 0;   
   
        for(int i = 0; i < 3; i++){   
            //*   
            ncount = 0;   
            char c = 'A' + i;   
            printf("%c:", c);//*/   
   
            for(int j = 0; j < k; j++){   
                if(pegs[i][j] != 0){   
                    printf("%d ", pegs[i][j]);   
                    ncount++;   
                }   
                   
            } 
            for(int i = 0; i < 2 * (k - ncount); i++) printf(" ");
            /*  
            if(c == 'A' || c == 'C'){   
                for(int i = 0; i < 2 * (k - ncount); i++) printf(" ");   
            }else{   
                for(int i = 0; i < 2 * (k - ncount) - 2; i++) printf(" "); 
                if(2 * k - 2 < 3){ 
                    for(int i = 0; i < 4 - (2 * k - 2); i++){ 
                        printf(" "); 
                    } 
                } 
                // if(4 - (2 * (k - ncount) - 2) > 0) printf(" ");   
            }//*/   
        }   
        // printf("B:    C:\n");   
        printf("\n");   
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
   
    int t, n;   
    scanf("%d", &t);   
    while(t--){ 
        cont = 1; 
        scanf("%d", &n);   
        k = n;
        int pegs[3][19] = {0}; 
        for(int i = 0; i < n; i++){   
            pegs[0][i] = n - i;   
        }   
        int npegs[3] = {n, 0, 0};   
         
        printf("    Initial configuration>     A:");   
        for(int i = 0; i < n; i++) printf("%d ", pegs[0][i]);   
        // printf("\n");   
        printf("B:");   
        for(int i = 0; i < 2 * n; i++) printf(" ");   
        /*
        if(4 - (2 * n - 1) > 0){   
            for(int i = 0; i < 4 - (2 * n - 2); i++){   
                printf(" ");   
            }   
        } //*/  
        printf("C:");   
        for(int i = 0; i < 2 * n; i++) printf(" ");   
        printf("\n");   
   
        tower(n, 'A', 'B', 'C', npegs, pegs);
    }   
}