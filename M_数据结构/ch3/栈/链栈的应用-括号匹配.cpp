 
#include<stdio.h>
#include<string.h>
#include "slink.h"	//包含前面的链栈基本运算函数


int Match(char exp[],int n)	//exp存放表达式，n是表达式长度
{ 
    LinkStack st;			//定义一个链栈st
   InitStack(st);		 //栈初始化
   int flag=1,i=0;
   char ch;  //出栈字符
   /********** Begin **********/ 
    while(i<n && flag==1)
    {
        switch(exp[i])
        {
            case '(': 
            case '[': 
            case '{':                                   
                    Push(st,exp[i]); //把左括号存入栈
                    break; //存入一个就break，去switch外面i++，存下一个
            case ')':   
                    if(!Pop(st,ch) || ch!='(') //如果出栈失败或不匹配----//！！注意，无论条件是否满足，pop()方法都会被执行
                        flag=0;
                    break;
            case ']':                              
                    if (!Pop(st,ch) || ch!='[')           
                        flag=0;
                    break;
            case '}':                               
                    if (!Pop(st,ch) || ch!='{')     
                        flag=0;
                    break;
        }
        i++;
    }
    if(StackEmpty(st) && flag==1) //如果栈被清空了并且flag=1
    {
        DestroyStack(st); //销毁栈st并返回1
        return 1;
    }
    else
    {
        DestroyStack(st); //销毁栈st并返回0
        return 0;
    }

 
   /********** End **********/
}


void display(char exp[])
{
    int n=strlen(exp);
    if (Match(exp,n))
        printf("%s是匹配的表达式\n",exp);
    else
        printf("%s不是匹配的表达式\n",exp);
}
int main()
{
    char str[80];
    scanf("%s",str);
    display(str);
    return 0;
}

