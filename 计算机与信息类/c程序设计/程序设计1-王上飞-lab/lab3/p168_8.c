#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1<<15
#define RANGE 1000

int matrix[MAX][MAX];
int  andian(int m,int n)
{
    int tmp,i,j,k,ct=0;
    for(i=0;i<m;++i){
        tmp = matrix[i][0];
        k=0;
        for(j=1;j<n;++j){
            if(tmp<matrix[i][j]){
                tmp=matrix[i][j];
                k = j;
            }
        }
        for(j=0;j<m;++j)if(tmp>matrix[j][k])break;
        if(j==m){
            printf("matrix[%d][%d]: %d\n",i,k,tmp);
            ++ct;
        }
    }
    return ct; 
}

int main()
{
    int m,n,i,j;
    srand((unsigned)time(NULL));
    printf("输入二维数组的行数: ");
    scanf("%d",&m); 
    printf("输入二维数组的列数: ");
    scanf("%d",&n); 
    printf("使用随机数初始化: \n"); 
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            matrix[i][j] = rand()%RANGE;
            printf("%d ",matrix[i][j]); 
        }
        printf("\n");
    }
    printf("鞍点: \n");
    if(andian(m,n)==0)printf("没有\n");
    return 0;
}
