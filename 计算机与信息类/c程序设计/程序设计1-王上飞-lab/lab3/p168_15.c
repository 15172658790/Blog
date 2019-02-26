#include<stdio.h>

int copy(char s1[],char s2[])
{
    int i=0;
    while(s1[i]=s2[i])++i;
    return i;
}
int main()
{
    char s1[1000],s2[10000];
    puts("输入要被复制的字符串: ");
    scanf("%s",s2);
    copy(s1,s2);
    puts("复制后:"); 
    puts(s1);
    return 0;
}
