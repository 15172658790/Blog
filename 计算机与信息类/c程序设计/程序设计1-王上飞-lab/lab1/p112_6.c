#include<stdio.h>
#include<math.h>

int f(int x)
{
    if(x<1)return x;
    else if(x<10) return 2*x-1;
    else return 3*x-11;
}
int main(int argc,char **argv)
{
        printf("%s\n",argv[0]);
        int xs[]={0,5,10};
        for(int i=0;i<3;++i)        printf("x=%d, y=%d\n",xs[i],f(xs[i]));
            return 0;
}

