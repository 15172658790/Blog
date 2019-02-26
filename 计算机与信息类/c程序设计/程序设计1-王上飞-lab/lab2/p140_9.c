#include<stdio.h>
int facSum(int n)
{
    int i,s=0;
    if(n==0)return 0;
    for(i=1;i<=n/2;i++){
        if(n%i==0)s+=i; 
    }
    return s;
}
int main()
{
    int i=6,n=1000;
    printf("%d 以内的完全数",n);
    for(;i<n;i++)
        if(facSum(i)==i)printf("%d ",i);
    return 0;
}
