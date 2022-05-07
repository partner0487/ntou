#include <stdio.h>

static int state = 0;
void set(int seed) {
    state = seed;
}
int next() {
    state = (state * 0x343FD + 0x269EC3) & 0x7FFFFFFF;
    return state >> 15; // maximum is 65535, minimum is 0
}

int main()
{
    int n, seed, data[1000000]={0};
    scanf("%d", &n, &seed);
    set(seed);
    for(int i=0;i<n;i++){
        data[i]=next();
    }
}