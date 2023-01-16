//fileTxt.cpp
#include <stdio.h>
// 函数extractDigit的功能：从文件a.txt中提取数值写入文件b.txt中
void extractDigit();
char readADigit(FILE *fi)
{
    char c = fgetc(fi);  // 从文件读取一个字符
    if(c==EOF)  // 是结束符则返回
    {
        return EOF;
    }
    while(c>'9' || c<'0')  // 如果不是数字字符，则继续读取下一个字符
    {
        c = fgetc(fi);  // 读取下一个字符
        if(c==EOF)  // 是结束符则返回
        {
            return EOF;
  	} 
    }
    return c;  // 返回读取的数字字符
}
// 函数extractDigit的功能：从文件a.txt中提取数值写入文件b.txt中
void extractDigit()
{
    FILE *fi = fopen("a.txt","r");  // 以读的方式打开文件a.txt
    FILE *fo = fopen("b.txt","w");  // 以写的方式打开文件b.txt
    if(fi==NULL || fo==NULL)  // 如果某个文件打开失败，则返回
    {
        return;
    }    
    char c;
    int num=0,k=0;
    c = readADigit(fi);  // 读取一个数字字符
    while(c!=EOF)
    {
        num=num*10+c-'0';  // 计算数字字符构成的整数
        k++;
        if(k==3)  // 已经三位了
        {
            fprintf(fo,"%d ",num);  // 将计算的整数写入文件指针fo指向的文件
            k=0;  // 重新计数
            num=0;  // 重新计算
     }
        c = readADigit(fi);  // 读取下一个数字字符
    }
    if(k!=0)  // 如果有不到三位的数值，则写入文件b.txt
    {
        fprintf(fo,"%d ",num);
    }
    fclose(fi);  // 关闭文件fi
    fclose(fo);  // 关闭文件fo
}
