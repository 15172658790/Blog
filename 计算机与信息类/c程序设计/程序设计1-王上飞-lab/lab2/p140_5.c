#include<stdio.h>
#include<math.h>
int main()
{
    int a,n;
    printf("input a: ");
    scanf("%d",&a);
    printf("input n: ");
    scanf("%d",&n);
    long long int s = 0;
    s = a*((2*pow(10,n+1)-20-9*n*(n+1))/2/81); 
    printf("result is : %lld", s);
    return 0; 
}
