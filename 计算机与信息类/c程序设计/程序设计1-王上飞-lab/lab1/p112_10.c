#include<stdio.h>
#include<math.h>

int main(int argc,char **argv)
{
        printf("%s\n",argv[0]);
        printf("输入奖金: ");
        int n;
        scanf("%d",&n);
        if(n<=1e5)printf("%.2f",n*0.1);
        else if(n<=2e5)printf("%.2f",1e4+(n-1e5)*0.075); 
        else if(n<=4e5)printf("%.2f",1e4+7500+(n-2e5)*0.05); 
        else if(n<=6e5)printf("%.2f",1e4+7500+10000+(n-4e5)*0.015); 
        else printf("%.2f",1e4+7500+10000+6000+(n-6e5)*0.01); 
            return 0;
}

