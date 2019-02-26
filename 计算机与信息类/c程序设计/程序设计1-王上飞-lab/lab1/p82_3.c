#include<stdio.h>
#include<math.h>

int main(int argc,char **argv)
{
    printf("%s\n",argv[0]);
    int d =3e5, p=6e3;
    float r=0.01;
    float m = log10(p/(p-d*r))/log10(1+r);
    printf("需 %.1f个月还清\n",m+0.05);
    printf("----------------\n\n");
    return 0;
}
