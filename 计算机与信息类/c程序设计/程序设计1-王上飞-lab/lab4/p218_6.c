#include<stdio.h>

void concat(char *des,char *s1,char *s2)
{
    int a=-1,b=-1;
    while(des[++a]=s1[++b]);
    b=-1;
    while(des[a++]=s2[++b]);
}

int main()
{
    char s1[100],s2[100],des[1000];
    printf("input s1: ");
    scanf("%s",s1); 
    printf("input s2: ");
    scanf("%s",s2); 
    concat(des,s1,s2);
    printf("after concat: %s",des);
    return 0;
}

