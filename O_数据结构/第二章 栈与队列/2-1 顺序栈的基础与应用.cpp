#include <stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define OVERFLOW -1
 
#define  STACK_INIT_SIZE   100  //存储空间初始分配量 
#define  STACKINCREMENT    10   //存储空间分配增量  
typedef int SElemType; // 定义栈元素类型为整型
/* 顺序栈类型定义 */
typedef   struct
{          
    SElemType     *base;    //栈的基址即栈底指针          
    SElemType     *top;     //栈顶指针          
   int      stacksize;       //当前分配的空间 
}SqStack; 

void input(SElemType &s);
void output(SElemType s);

void InitStack(SqStack &S);// 构造一个空栈S
void DestroyStack(SqStack &S); // 销毁栈S，S不再存在
void ClearStack(SqStack &S); // 把S置为空栈
int StackEmpty(SqStack S); // 若栈S为空栈，则返回TRUE，否则返回FALSE
int StackLength(SqStack S); // 返回S的元素个数，即栈的长度
int GetTop(SqStack S,SElemType &e);  // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
void Push(SqStack &S,SElemType e);    // 插入元素e为新的栈顶元素
int Pop(SqStack &S,SElemType &e);   // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
void StackTraverse(SqStack S,void(*visit)(SElemType)); // 从栈底到栈顶依次对栈中每个元素调用函数visit()


int main()
 {
   int j;
   SqStack s;
   SElemType e;
   InitStack(s);
   int i;
   cin>>i;
   for(j=0;j<i;j++)  
   {  
       input(e);  
       Push(s,e);  
   }  
   printf("栈中元素依次为：");
   StackTraverse(s,output);
   Pop(s,e);
   printf("弹出的栈顶元素 e=%d\n",e);
   printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
   GetTop(s,e);
   printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
   ClearStack(s);
   printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
   DestroyStack(s);
   printf("销毁栈后，s.top=%u s.base=%u s.stacksize=%d\n",s.top,s.base, s.stacksize);
 }
/*****SElemType类型元素的基本操作*****/
void input(SElemType &s)
{
    cin>>s;
}
void output(SElemType s)
{
    cout<<s<<" ";
}

/*****顺序栈的基本操作*****/
void InitStack(SqStack &S)
{ 
	// 构造一个空栈S
    /********** Begin **********/ 
    S.base  = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(int));
    if(!S.base)
        return ;// 分配失败
    S.top  = S.base;// 栈的初始状态
    S.stacksize = STACK_INIT_SIZE;
 

    /********** End **********/  
}

void DestroyStack(SqStack &S)
{ 
	// 销毁栈S，S不再存在
    /********** Begin **********/ 

    S.base = 0;
    S.top = 0;
    S.stacksize = 0;
    free(S.base);
    free(S.top);

    /********** End **********/ 	
}

void ClearStack(SqStack &S)
{ 
 	// 把S置为空栈
    /********** Begin **********/
    S.top = S.base; 

    /********** End **********/ 
}


int StackEmpty(SqStack S)
{
 	// 若栈S为空栈，则返回TRUE，否则返回FALSE
    /********** Begin **********/ 
    if(S.top == S.base)return 1;
    else return 0;
    /********** End **********/	
 }


int StackLength(SqStack S)
{ 
	// 返回S的元素个数，即栈的长度
    /********** Begin **********/
    return  S.top - S.base;



    /********** End **********/  
}


int GetTop(SqStack S,SElemType &e)
{ 
    // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    /********** Begin **********/ 
    if(S.top > S.base){
        e  = *(S.top-1);
        return OK;
    }
    else
        return ERROR;

    /********** End **********/	
}


void Push(SqStack &s,SElemType e)
{     
	// 插入元素e为新的栈顶元素
    /********** Begin **********/ 
    // 第一种 追加存储空间 的栈

	if (s.top - s.base >= s.stacksize)
	{
		s.base = (SElemType*)realloc(s.base, (s.stacksize + STACKINCREMENT )* sizeof(SElemType));	
		
        if (!s.base)
			return;

		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}
	*s.top = e;
	s.top++;

    /********** End **********/	
}

int Pop(SqStack &S,SElemType &e)
{   
	// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    /********** Begin **********/ 
    if(S.top > S.base ){
      S.top -- ;

    }

    /********** End **********/ 	
}

void StackTraverse(SqStack S,void(*visit)(SElemType))
{ 
	// 从栈底到栈顶依次对栈中每个元素调用函数visit()
    /********** Begin **********/ 
    while(S.top > S.base){
        visit(*(S.base)++);
    }
    printf("\r\n");

    /********** End **********/	
}
