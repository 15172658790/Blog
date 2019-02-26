#include<stdio.h>

int main()
{
    float s[10][5],sum,sum2,avg[10];
    int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<5;j++){
            printf("学生 %d 成绩 %d: ",i+1,j+1);
            scanf("%f",&s[i][j]);
        }
    for(i=0;i<10;++i){
        sum=0; 
        for(j=0;j<5;++j)sum+=s[i][j];
        avg[i]=sum/5; 
        printf("第 %d 个学生的平均分: %f\n",i+1,sum/5);
    }
    for(i=0;i<5;++i){
        sum=0; 
        for(j=0;j<10;++j)sum+=s[j][i];
        printf("第 %d 门课的平均分: %f\n",i+1,sum/10);
    }

    sum=sum2=0;
    for(i=0;i<10;++i){
        sum +=avg[i];
        sum2 +=avg[i]*avg[i];
    }
    printf("平均分方差为: %f\n",sum2/10-sum*sum/100);
    return 0;
}
