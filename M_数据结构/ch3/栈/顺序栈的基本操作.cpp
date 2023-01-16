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

/*
typedef   struct
{          
    SElemType     *base;    //栈的基址即栈底指针          
    SElemType     *top;     //栈顶指针          
   int      stacksize;       //当前分配的空间 
}SqStack; 
*/

/*****顺序栈的基本操作*****/
void InitStack(SqStack &S)
{ 

	// 构造一个空栈S
    
    /********** Begin **********/ 
    //栈底指针：base ，不允许插入和删除的一端，指向栈空间的开头
    //栈顶指针：top ，允许插入和删除的一端
    if(!(S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType)))) //如申请栈的空间失败则退出  
        exit(OVERFLOW); // 存储分配失败
    S.top=S.base;  // 栈顶指针 = 栈底指针
	S.stacksize=STACK_INIT_SIZE; //当前分配的空间=存储空间初始分配量
    //stacksize是当前所分配的空间
    //STACK_INIT_SIZE是存储空间初始分配量，上面设为了100 

    /********** End **********/  
}

void DestroyStack(SqStack &S)
{ 
	// 销毁栈S，S不再存在
    /********** Begin **********/ 
	free(S.base); //因为构造栈时是用S.base为首指针来申请空间的，这里视为空间
	S.base=NULL; //栈底指针指向NULL
	S.top=NULL; //栈顶指针指向NULL
	S.stacksize=0; //当前分配空间设为0
    /********** End **********/ 	
}

void ClearStack(SqStack &S)
{ 
 	// 把S置为空栈
    /********** Begin **********/ 
    S.top=S.base;

    /********** End **********/ 
}


int StackEmpty(SqStack S)
{
 	// 若栈S为空栈，则返回TRUE，否则返回FALSE
    /********** Begin **********/ 
	if(S.top==S.base)
      return TRUE;
	else
      return FALSE; 	
    /********** End **********/	
 }


int StackLength(SqStack S)
{ 
	// 返回S的元素个数，即栈的长度
    /********** Begin **********/ 
    
    return S.top-S.base;
    
    /********** End **********/  
}


int GetTop(SqStack S,SElemType &e)
{ 
    // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    /********** Begin **********/ 
	if(S.top>S.base)
   {
     e=*(S.top-1); //top指向栈顶元素的下一位
     return OK;
   }
   else
     return ERROR;
    /********** End **********/	
}


void Push(SqStack &S,SElemType e)
{     
	// 插入元素e为新的栈顶元素
    /********** Begin **********/ 
	if(S.top-S.base>=S.stacksize) //等于的时候就已经超出一格
	{
     S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType)); // 栈满，追加存储空间STACKINCREMENT
     if(!S.base)
       exit(OVERFLOW); // 存储分配失败
     S.top=S.base+S.stacksize; //栈顶指针 = 栈底指针+栈的当前存储空间(比原来栈满的位置上一格)，因为空间已经扩大，故没问题
     S.stacksize+=STACKINCREMENT; //当前存储空间=原始当前存储空间+追加存储空间
	}
   *(S.top)++=e;  //*S.top = e , S.top++ //栈顶元素设为e，栈顶指针指向下一位
    /********** End **********/	
}

int Pop(SqStack &S,SElemType &e)
{   
	// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    /********** Begin **********/ 
	if(S.top==S.base) //如果栈为空则返回0
        return ERROR;
	e=*--S.top; //即 e = *(S.top-1), s.top-- //栈顶元素用e返回，栈顶指针指回上一位
	return OK;
    /********** End **********/ 	
}

void StackTraverse(SqStack S,void(*visit)(SElemType))
{ 
	// 从栈底到栈顶依次对栈中每个元素调用函数visit()
    /********** Begin **********/ 
    
	while(S.top>S.base)
		visit(*S.base++);
	printf("\n");

    /********** End **********/	
}
