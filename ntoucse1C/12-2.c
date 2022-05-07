#include<stdio.h>
#define xiaoyox
// #define and &&
// #define or ||
// typedef _Bool bool;

int mapp[81]={}, ans[81];
int cont=0;
bool rol[9][10]={},col[9][10]={},block[9][10]={};
void dfs(int now){
    if(now==81){
        cont++;
        if(cont==1) 
            for(int i=0;i<81;i++) ans[i]=mapp[i];
        return ;
    }
    if(mapp[now]!=0) dfs(now+1);
    else{
        for(int i=1;i<=9;i++){
            int tr=now%9,tc=now/9;
            if(rol[tr][i] || col[tc][i] || block[(now/27)*3+(tr/3)][i]) continue;
            rol[tr][i] = col[tc][i] = block[(now/27)*3+(tr/3)][i]=1;
            mapp[now]=i;
            dfs(now+1);
            mapp[now]=0;
            rol[tr][i] = col[tc][i] = block[(now/27)*3+(tr/3)][i]=0;
        }
    }
}
int main(){
    #ifdef xiaoyo
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int m,n,num;
        scanf("%d, %d, %d",&m,&n,&num);
        mapp[m*9+n]=num;
        col[m][num]=1;
        rol[n][num]=1;
        block[(m/3)*3+n/3][num]=1;
    }
    dfs(0);
    printf("number of solutions=%d\n",cont);
    if(cont==1){
        for(int j=0;j<9;j++){
            for(int l=0;l<9;l++)
                printf(" %d",ans[j*9+l]);
            printf("\n");
        }
    }
}