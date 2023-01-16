#include <stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

typedef int SElemType; // 定义栈元素类型为整型

#include "sqstack.h"  // 顺序栈的类型定义，自己写的头文件，头文件是被其他的.cpp包含进去，在.cpp文件中得到编译。头文件中只放变量和函数的声明，而不能放它们的定义

void conversion(unsigned n)
{ 
	// 对于输入的任意一个非负10进制整数，打印输出与其等值的16进制数
   /********** Begin **********/ 

   SqStack s; //声明栈
   SElemType e;
   InitStack(s);
   unsigned temp = 0; //非负整数temp
   while(n)
   {
      temp = n%16;
      Push(s, temp);
      n = n/16;
   }
   while(!StackEmpty(s)) //当栈非空
   {
      Pop(s, e);
      printf("%X",e); //输出e的十六进制
   }
	/********** End **********/	
}

int main()
{  
    unsigned n; // 非负整数
    scanf("%u",&n); // 输入非负十进制整数n
    conversion(n);
 }
