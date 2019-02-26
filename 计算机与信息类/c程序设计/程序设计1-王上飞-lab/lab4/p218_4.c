#include<stdio.h>
#define N 1000
int mat[N][N]={{1,2,3,4},{5,6,7,8}};

void printMat(int m,int n)
{
    int i,j;
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            printf("%d ",mat[i][j]);
        }
            printf("\n");
    }
    return;
}

void transpose(int m,int n)
{
    // mat is a matrix with form of  max(m,n) x max(m,n)
    int i,j,tmp,min;
    min = m>n ? n:m;
    for(i=0;i<min;++i)
        for (j=i+1;j<min;++j){
            tmp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = tmp;
        }
    if(m>n){
        for(i=n;i<m;++i)
            for(j=0;j<n;++j)mat[j][i] = mat[i][j];
    }else if(m<n){
        for(i=m;i<n;++i)
            for(j=0;j<m;++j)mat[i][j] = mat[j][i];
    }
}

int main()
{
    int m,n,i,j;
    printf("Example\nBefore transposing\n");
    printMat(4,2);
    transpose(4,2);
    printf("After transposing\n"); 
    printMat(2,4);

    printf("input row num: ");
    scanf("%d",&m); 
    printf("input col num: ");
    scanf("%d",&n); 
    for(i=0;i<m;++i)
        for(j=0;j<n;++j){
            printf("input matrix[%d][%d]: \n",i,j);
            scanf("%d",&mat[i][j]);
        }
    printf("Before transposing\n");
    printMat(m,n);
    transpose(m,n);
    printf("After transposing\n"); 
    printMat(n,m);
    return 0;
}
