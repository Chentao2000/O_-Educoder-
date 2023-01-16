#include <stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

typedef int SElemType; // 定义栈元素类型为整型

#include "sqstack.h"  // 顺序栈的类型定义

void conversion(unsigned n)
{ 
	// 对于输入的任意一个非负10进制整数，打印输出与其等值的16进制数
   /********** Begin **********/ 
   SqStack s;
   SElemType e;
   InitStack(s); /* 初始化栈 */
   unsigned temp = 0;
   while(n) /* 当n不等于0 */
   {
       temp = n%16;

     Push(s,temp); /* 入栈n除以8的余数(8进制的低位) */
     n=n/16;
   }
   while(!StackEmpty(s)) /* 当栈不空 */
   {
     Pop(s,e); /* 弹出栈顶元素且赋值给e */
     printf("%X",e); /* 输出e */
   }
	/********** End **********/	
}

int main()
{  
    unsigned n; // 非负整数
    scanf("%u",&n); // 输入非负十进制整数n
    conversion(n);
 }
