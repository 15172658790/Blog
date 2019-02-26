#include<stdio.h>

void concat(char s1[],char s2[])
{
    int i=0,j=0;
    while(s1[i])++i;
    while(s1[i++]=s2[j++]);
}

int main()
{
    char s1[1000] = "hello";
    char s2[] = ", world";
    printf("s1: %s\ns2: %s\n",s1,s2);
    concat(s1,s2);
    printf("连接后: \n%s",s1);
    return 0;
}

