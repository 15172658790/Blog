#include<stdio.h>

//使用康托展开计算全排列, 下面存储的是0!,1!,2!...(n-1)!
long long int fac[100]={}; 
void calFac(int n)
{
    int i;
    fac[0]=1;
    for(i=1;i<=n;i++){
        fac[i]=i*fac[i-1];
    }
}

/* 思路是, 设置一个数组, 索引编号分别对应 甲 队的成员A,B,C... , 数组的值对应 乙队的成员 X,Y,Z...*/
void getArrangement(int *arr,int n,int sum)
{
    /*从整数 sum 得到一个 n位的排列存储到 arr 中*/
    int i,j,ct=0,k, ct2;
    int flag[n];
    for(i=0;i<n;i++)flag[i]=1;

    for(i=n-1;i>=0;i--){
        for(j=i;j>=0;j--){
            if(j*fac[i]<=sum){
                ct2=0;
                for(k=0;k<n;++k){
                    //printf("i%d  j%d  k%d\n",i,j,k);
                    if(flag[k]==1)ct2++;
                    if(ct2>j)break; 
                }
                arr[ct++] = k;
                flag[k]=0; 
                sum -=j*fac[i]; 
                break;
            }
        }
    }
}

void nextArrangement(int *arr, int n)
{//todo
}
int main(int argc,char **argv)
{
    int n=6, arr[n],i;
    long long int f=0;
    calFac(n);
    for(f=0;f<fac[n];++f){
        getArrangement(arr,n,f);
        if(arr[0]!=0 && arr[2]!=0 &&arr[2]!=2)break;
    }
    printf("给甲乙队编号 0,1,2...\n");
    printf("甲队: ");
    for(i=0;i<n;i++)printf("%d ",i);
    printf("\n乙队: ");
    for(i=0;i<n;i++)printf("%d ",arr[i]);
    return 0;
}
