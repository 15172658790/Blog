#include<stdio.h>
#define MAX 1<<15
int primes[MAX];
void findPrime(int max)
{
    int i,j;
    for(i=2;i<=max;++i) primes[i] = 1;
    for(i=2;i<max;++i)
        for(j=i+1;j<=max;++j) if(primes[j]==1 && j%i==0)primes[j]=0;
    printf("primes below %d are:\n",max);
    for(i=2;i<=max;++i)if(primes[i]==1)printf("%d ",i);
    printf("\n");
}

int main()
{
    findPrime(100);
    return 0;
}
