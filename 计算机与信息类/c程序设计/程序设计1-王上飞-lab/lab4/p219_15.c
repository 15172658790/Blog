#include<stdio.h>
#include<malloc.h>

struct employee{
    int no;
    char s[20];
}; 

struct employee *emp[1000];

void quickSort(int begin,int end)
{
    if(begin>=end)return ;
    struct employee *p = emp[0]; 
    int originBeg = begin,originEnd = end; 
    while(begin<end){
        while(end>begin && p->no<emp[end]->no) end--;
        if(begin<end)emp[begin++] = emp[end]; 
        while(end>begin && p->no>emp[begin]->no) begin++;
        if(begin<end)emp[end--] = emp[begin]; 
    }
    emp[begin] = p; 
    quickSort(originBeg,begin-1);
    quickSort(begin+1,originEnd);
}

int  binary_find(int no,int end)
{
    int begin=0,j,mid; 
    while(1){
        if(begin>end)break;
        mid =(begin+end)/2;
        if(emp[mid]->no==no)return mid;
        else if(emp[mid]-> no<no) begin = mid+1;
        else end = mid-1;
    }
    return -1;
}
void getInput(int n)
{
    int i;
    for(i=0;i<n;++i){
        emp[i] = malloc(sizeof(struct  employee)); 
        printf("input employee %d 's name: ",i+1);
        scanf("%s",emp[i]->s);
        printf("input employee %d 's no: ",i+1);
        scanf("%d",&emp[i]->no);
    }
}

void finish(int n)
{
    int i;
    for(i=0;i<n;++i)free(emp[i]);
}

void print(int n)
{
    int i;
    for(i=0;i<n;++i)printf("%d  %s\n",emp[i]->no,emp[i]->s); 
}
int main()
{
    int i,n = 5;
    getInput(n);
    print(n); 
    quickSort(0,n-1);
    print(n); 
    while(1){
        printf("input employee 's no to search, input -1 to quit\n");
        scanf("%d",&i);
        if(i==-1)break;
        i = binary_find(i,n);
        printf("employee %d:  %s\n",emp[i]->no,emp[i]->s);
    }
    finish(n); 
    return 0;
}
