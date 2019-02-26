#include<stdio.h>
#include<math.h>
int digit(int n)
{
    int ct=0;
    do{
        printf("%d",n%10);
        n/=10;
        ct +=1;
    }while(n); 
    printf("共%d 位数字\n",ct);
    return ct;
}

int main(int argc,char **argv)
{
        printf("%s\n",argv[0]);
        digit(8650);

            return 0;
}

