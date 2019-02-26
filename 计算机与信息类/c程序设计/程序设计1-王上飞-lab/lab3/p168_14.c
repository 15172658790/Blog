#include<stdio.h>

int cmpStr(char s1[],char s2[])
{
    int i=0;
    while(s1[i]&&s2[i]&&s1[i]==s2[i])++i;
    return s1[i]-s2[i];
}
int main()
{
    char s1[1000] ,s2[1000];
    puts("输入 s1: ");
    gets(s1);
    puts("输入 s2: ");
    gets(s2); 
    printf("比较结果: %d",cmpStr(s1,s2));
    return 0;
}
