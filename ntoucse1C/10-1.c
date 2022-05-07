#include  <stdio.h>

int gcd(int a, int b){
    int tmp;
    if(a<b){
        tmp=b;
        b=a;
        a=tmp;
    }
    while(b){
        int k=a%b;
        a=b;
        b=k;
    }
    return a;
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}

int add(int s1, int m1, int s2, int m2){
    int k=lcm(m1,m2);
    s1=s1*k/m1;
    s2=s2*k/m2;
    return s1+s2,k;
}

/*int minus(int s1, int m1, int s2, int m2){
    
}

int muilty(int s1, int m1, int s2, int m2){
    
}

int devide(int s1, int m1, int s2, int m2){
    
}*/

int main(){
    int son1,mother1,son2,mother2;
    char c;
    int state=1;
    while(state==1){
        scanf("%d/%d%s%d/%d", &son1, &mother1, &c, &son2, &mother2);
        // scanf("%c", &c);
        // scanf("%d/%d", &son2, &mother2);
        if(int(c)==43){
            printf("%d/%d", add(son1,mother1,son2,mother2));
            state=0;
        }
        // else if(int(c)==45) printf("%d", minus(son1,mother1,son2,mother2));
        // else if(int(c)==42) printf("%d", muilty(son1,mother1,son2,mother2));
        // else if(int(c)==47) printf("%d", devide(son1,mother1,son2,mother2));
    }
}