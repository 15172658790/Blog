#include<stdio.h>

void reverse(char *p)
{
    int a=-1,b=0;
    char c;
    while (p[++a]);
    a-=1;
    while(a>b){
        c=p[a];
        p[a] = p[b];
        p[b] =c;
        a--;
        b++; 
    }
}

int main()
{
    char s[1000];
    printf("input  a string: ");
    scanf("%s",s);
    reverse(s); 
    printf("after reversing: %s",s);
    return 0;
}
