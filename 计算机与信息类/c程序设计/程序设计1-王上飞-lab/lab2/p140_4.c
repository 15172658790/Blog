#include<stdio.h>

void count(char * s)
{
    int en=0,space=0,num=0,other=0;
    int i=0;
    while(s[i]!='\0'&&s[i]!='\n'){
        if( s[i]<='9' && s[i]>='0') num++;
        else if (s[i]==' ') space++;
        else if ((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) en++;
        else other++;
        i++;
    }
    printf("alpha: %d\nnumber: %d\nspace: %d\nother: %d\n",en,num,space,other);
}

int main()
{
    int n= 1000;
    printf("input a string: ");
    char s[n];
    fgets(s,n,stdin); 
    count(s);
    return 0;
}
