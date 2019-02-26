#include<stdio.h>
#include<math.h>
double ratio[]={0.0414,0.0468,0.054,0.054,0.0585};

double dingqi(double money,int n,int *years)
{
    double rst = money; 
  for(int i=0;i<n;++i){
      rst *=(1+years[i] * ratio[years[i]]);
  }
  return rst;
}

double huoqi_ratio=0.0072;
double huoqi(double money,int n)
{
    return money*pow((1+huoqi_ratio),4*n);
}

int main(int argc,char **argv)
{
    printf("%s\n",argv[0]);
    double money = 1000;
    int a[]={5},b[]={2,3},c[]={3,2},d[]={1,1,1,1,1}; 
    printf("第一种: %.4lf\n",dingqi(money,1,a));
    printf("第二种: %.4lf\n",dingqi(money,2,b));
    printf("第三种: %.4lf\n",dingqi(money,2,c));
    printf("第四种: %.4lf\n",dingqi(money,5,d));
    printf("第五种: %.4lf\n",huoqi(money,5));
    printf("----------------\n\n");
    return 0;
}
