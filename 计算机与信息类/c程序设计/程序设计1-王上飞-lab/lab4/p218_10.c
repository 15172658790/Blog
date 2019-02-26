#include<stdio.h>

void findLongestWord(char *s)
{
    int begin,mx=0,i=0,p1,p2;
    int find=0;
    while(s[i]){
        if(('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z') || s[i]=='_' || s[i]=='-'){
            if(!find){
                find=1;
                begin=i;
            }
        }else{
            if(find&& i-begin>mx){
                mx = i-begin;
                p1 = begin;
                p2=i;
            }
            find=0;
        }
        i++;
    }
    if(find&& i-begin>mx){
        mx = i-begin;
        p1=begin;
        p2=i;
    }
    printf("longest word: ");
    while(p1<p2)putchar(s[p1++]);
}

int main()
{
    char s[1000];
    printf("input a string: ");
    gets(s); 
    findLongestWord(s);
    return 0;
}
