#include "syscall.h"

/*整数转字符串*/
void itoa(int n, char* line);

/*将数字写入文件*/
void writeNum(int num,int fid);

int main(){
    int result,resultReadF;         
    int fid1, fid2, fid3;
    char str[64];
	//测试Create和Open
    result = Create("test.txt");//成功创建test.txt文件，返回值为1
    Create("result.txt");//result.txt用来存储返回值
    fid1 = Open("test.txt");//打开存在的文件test.txt，打开成功，返回值为文件id
    fid2 = Open("result.txt");//打开存在的文件result.txt，打开成功，返回值为文件id
    fid3 = Open("fail.txt");  //打开不存在的文件，打开失败，返回值为-1
    //将以上返回值写入result.txt文件
    writeNum(result,fid2);
    writeNum(fid1,fid2);
    writeNum(fid2,fid2);
    writeNum(fid3,fid2);
    
    //测试Write，向test.txt文件（fid1）写入指定长度数据
    result = Write("SysCall Test for Nachos!\n",25,fid1);//返回值为写入的字符个数
    //将返回值写到result.txt文件
    writeNum(result,fid2);

    //测试close，成功关闭文件，返回值为1
    result = Close(fid1);
    //将返回值写入result.txt文件
    writeNum(result,fid2);

    fid1 = Open("test.txt");
    //测试读Read，从test.txt文件读取指定长度的数据
    result = Read(str,7,fid1); //成功读取数据，返回值为读取的字符个数
    //将返回值写到result.txt文件
    writeNum(result,fid2);
    //将读出的字符串写入result.txt
    Write(str,7,fid2);
    Write("\n",1,fid2);

    //关闭文件
    Close(fid1);
    Close(fid2);
    
    Halt();
}

void itoa(int n, char* line){
    int i=0;
    int j=0;
    int neg = -1;
    if(n<0) {
        n=-n;
        neg=1;
    }
    while(n){
        line[i++] = '0'+n%10;
        n/=10;
    }
    if(neg==1) line[i++] = '-';
    for(i=i-1;i>j;j++,i--){
        char t = line[i];
        line[i] = line[j];
        line[j] = t;
    }
}

void writeNum(int num,int fid){
    int cnt = 0;
    int t = num;
    char numStr[64];

    /*计算数字字符串长度*/
    if(t==0) {}
    else {
        if(t<0) cnt++;
        while(t){
            t/=10;
            cnt++;
        }
    }

    itoa(num,numStr);
    Write(numStr,cnt,fid);
    Write("\n",1,fid);
}