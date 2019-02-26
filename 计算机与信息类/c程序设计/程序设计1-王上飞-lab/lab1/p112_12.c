#include<stdio.h>
#include<math.h>
int  notIn(float x,float  y,int r)
{
    if((x+2)*(x+2)+(y-2)*(y-2)<=r*r)return 0; 
    if((x-2)*(x-2)+(y-2)*(y-2)<=r*r)return 0; 
    if((x+2)*(x+2)+(y+2)*(y+2)<=r*r)return 0; 
    if((x-2)*(x-2)+(y+2)*(y+2)<=r*r)return 0; 
    return 1; 
}

int main(int argc,char **argv)
{
        printf("%s\n",argv[0]);
        printf("输入坐标, 以空格分开: "); 
        float x,y;
        scanf("%f %f",&x,&y);
        if(!notIn(x,y,1)) printf("10m\n");
        else printf("0m\n");
            return 0;
}

