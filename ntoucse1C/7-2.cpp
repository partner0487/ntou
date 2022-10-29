#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  

char str[2000]={};  
int str2[2000]={};  

void trans(int len)  
{  
    for(int i=len-1;i>=0;i--)  
    {  
        if('0'<=str[i] && str[i]<='9')  
            str2[i]=str[i]-'0';  
        if('a'<=str[i] && str[i]<='z')  
            str2[i]=str[i]-'a'+36;  
        if('A'<=str[i] && str[i]<='Z')  
            str2[i]=str[i]-'A'+10;  
    }  
}  
int main()  
{  
    while(scanf("%s",str)!=EOF)  
    {  
        int len=strlen(str),ans=0;  
        trans(len);  
        int f=0;  
        int MAX=0;  
        for(int i=len-1;i>=0;i--)  
        {  
            if(str2[i]>=MAX) MAX=str2[i];  
        }  
        for(int x=MAX+1;x<=62;x++)  
        {  
            long long total=0,sum=0;  
            int times=0;  
            for(int i=len-1;i>=0;i--)  
            {  
                sum=str2[i];  
                if(times>0)  
                {  
                    int n=times;  
                    while(n--)  
                    {  
                        sum*=x;  
                    }  
                    total+=sum;  
                }  
                else  
                    total+=sum;  
                times++;  
            }  
            if(total%(x-1)==0)  
            {  
                f=1;  
                ans=x;  
                break;  
            }  
        }  
        if(f)  
            printf("%d\n",ans);  
        else  
            printf("-1\n");  
    }  
}