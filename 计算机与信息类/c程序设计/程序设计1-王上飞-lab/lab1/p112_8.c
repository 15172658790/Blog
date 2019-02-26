#include<stdio.h>
#include<math.h>

char score(int n)
{
    if(n>=90)return 'A';
    else if (n>=80)return 'B';
    else if (n>=70)return 'C';
    else if (n>=60)return 'D';
    else return 'E';
}
int main(int argc,char **argv)
{
        printf("%s\n",argv[0]);
        int ns[]={56,66,76,86,96};
        for(int i=0;i<5;++i)
        printf("分数:%d 成绩: %c\n",ns[i],score(ns[i])); 
            return 0;
}

