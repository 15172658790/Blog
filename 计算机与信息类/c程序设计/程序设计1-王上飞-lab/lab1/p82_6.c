#include<stdio.h>

char encrypt(char c)
{
    c = c+4;
    if(( c<'a'&&c>'Z') || c>'z') c-=26;
    return c;
}
int main(int argc,char **argv)
{
    printf("%s\n",argv[0]);

    char c[] = {'C','h','i','n','a'};
    printf("putchar: ");
    for(int i=0;c[i]!='\0';++i){
        c[i]=encrypt(c[i]);
        putchar(c[i]);
    }
    
    printf("\nprintf: %s\n",c);
    printf("----------\n\n"); 
    return 0;
}

