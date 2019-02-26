#include<stdio.h>
#include<math.h>
void sort(int n,int *arr)
{
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(arr[j]>arr[j+1]){
                int tmp=arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= tmp;
            }
        }
    }
}
int main(int argc,char **argv)
{
        printf("%s\n",argv[0]);
        printf("input n: ");
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++)scanf("%d",a+i);
        sort(n,a);
        for(int i=0;i<n;i++)printf("%d ",a[i]);
        printf("\n\n"); 
            return 0;
}


