#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1<<15

#define init 20
#define range 1000

int nums[MAX];
void quickSort(int *arr,int begin,int end)
{
    if(begin>=end)return; 
    int originBegin = begin,originEnd = end; 
    int pivot = arr[begin];
    while(begin<end){
        while(begin<end && arr[end]>pivot)--end;
        if(begin<end)arr[begin++] = arr[end];
        while(begin<end && arr[begin]<pivot)++begin; 
        if(begin<end)arr[end--] = arr[begin];
    }
    arr[begin] = pivot;
    quickSort(arr,originBegin,begin-1);
    quickSort(arr,begin+1,originEnd);
}

void printArr(int *arr,int len)
{
    int i;
    for(int i=0;i<len;++i){
//        if(i%8==0)printf("\n");
        printf("%d ",arr[i]);
    }
    printf("\n"); 
}
void insert(int *arr, int len,int n)
{
    int i;
    for(i=init;i>0&&arr[i-1]>n;--i) arr[i]=arr[i-1];
    arr[i] = n;
}

int main()
{
    int i,n;
    srand((unsigned)time(NULL)); //gen random seed
    for(i=0;i<init;++i)nums[i] = rand()%range;
    printf("随机产生了长为 %d 序列: \n",init);
    printArr(nums,init);
    printf("排序后: \n");
    quickSort(nums,0,init-1);
    printArr(nums,init);
    printf("输入一个整数: ");
    scanf("%d",&n);
    insert(nums,init,n);
    printf("插入 %d 后, 序列为: \n",n);
    printArr(nums,init+1);
    return 0;
}
