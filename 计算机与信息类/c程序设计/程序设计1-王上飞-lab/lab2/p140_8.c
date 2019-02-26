#include<stdio.h>
#include<math.h>

int main()
{
    int i=0, a,b,c,ct=0;
    printf("所有水仙花数: \n");
    for(i=100;i<1000;++i){
        a = i/100;
        b=i%100 /10;
        c=i%10;
        if(pow(a,3)+pow(b,3)+pow(c,3)==i){
            printf("%d, ",i);
            ct+=1;
            if(ct%8==0)printf("\n");
        }
    }
    return 0;
}
