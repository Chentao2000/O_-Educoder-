#include <stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
typedef  int  SElemType;     //！！这里吧int命名为SElemType了
void input(SElemType &s);
void output(SElemType s);

typedef  SElemType  ElemType;   // 栈结点类型和链表结点类型一致

struct  LNode
 {
   ElemType data;
   LNode *next;
 };
 typedef  LNode * LinkList; // 另一种定义LinkList的方法

// 不带头结点的单链表的部分基本操作(9个)
 #define DestroyList ClearList // DestroyList()和ClearList()的操作是一样的
 void InitList(LinkList &L); 
 void ClearList(LinkList &L);
 int ListEmpty(LinkList L);
 int ListLength(LinkList L);
 int GetElem(LinkList L,int i,ElemType &e);
 int LocateElem(LinkList L,ElemType e,int(*compare)(ElemType,ElemType));
 int ListInsert(LinkList &L,int i,ElemType e);
 int ListDelete(LinkList &L,int i,ElemType &e);
 void ListTraverse(LinkList L,void(*vi)(ElemType));

 /*****链栈的基本操作*****/    //！！这里把LinkList再命名为LinkStack了
typedef  LinkList LinkStack;     // LinkStack是指向栈结点的指针类型
#define  InitStack  InitList     // InitStack()与InitList()作用相同，下同
#define DestroyStack  DestroyList
#define ClearStack  ClearList
#define StackEmpty  ListEmpty
#define StackLength ListLength

int GetTop(LinkStack S,SElemType &e); // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
int Push(LinkStack &S,SElemType e);  // 插入元素e为新的栈顶元素
int Pop(LinkStack &S,SElemType &e); // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
void StackTraverse(LinkStack S,void(*visit)(SElemType)); // 从栈底到栈顶依次对栈中每个元素调用函数visit()


int main()
 {
   int j,n;
   LinkStack s;
   SElemType e;
   InitStack(s);
   cin>>n;
   for(j=1;j<=n;j++)
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

// 不带头结点的单链表的部分基本操作(9个)
#define DestroyList ClearList    // DestroyList()和ClearList()的操作是一样的
void InitList(LinkList &L)
{ // 操作结果：构造一个空的线性表L
   L=NULL; // 指针为空
}

void ClearList(LinkList &L)
{ // 初始条件：线性表L已存在。操作结果：将L重置为空表
   LinkList p;
   while(L) // L不空
   {
     p=L; // p指向首元结点
     L=L->next; // L指向第2个结点(新首元结点)
     free(p); // 释放首元结点
   }
}

int ListEmpty(LinkList L)
{ // 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE
   if(L)
     return FALSE;
   else
     return TRUE;
}

int ListLength(LinkList L)
{ // 初始条件：线性表L已存在。操作结果：返回L中数据元素个数
   int i=0;
   LinkList p=L;
   while(p) // p指向结点(没到表尾)
   {
     p=p->next; // p指向下一个结点
     i++;
   }
   return i;
}

int GetElem(LinkList L,int i,ElemType &e)
{ // L为不带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
   int j=1;
   LinkList p=L;
   if(i<1) // i值不合法
     return ERROR;
   while(j<i&&p) // 没到第i个元素，也没到表尾
   {
     j++;
     p=p->next;
   }
   if(j==i) // 存在第i个元素
   {
     e=p->data;
     return OK;
   }
   else
     return ERROR;
}

int LocateElem(LinkList L,ElemType e,int(*compare)(ElemType,ElemType))
{ // 初始条件：线性表L已存在，compare()是数据元素判定函数(满足为1，否则为0)
   // 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
   //           若这样的数据元素不存在，则返回值为0
   int i=0;
   LinkList p=L;
   while(p)
   {
     i++;
     if(compare(p->data,e)) // 找到这样的数据元素
       return i;
     p=p->next;
   }
   return 0;
}

int ListInsert(LinkList &L,int i,ElemType e)
{ // 在不带头结点的单链线性表L中第i个位置之前插入元素e
   int j=1;
   LinkList p=L,s;
   if(i<1) // i值不合法
     return ERROR;
   s=(LinkList)malloc(sizeof(LNode)); // 生成新结点
   s->data=e; // 给s的data域赋值
   if(i==1) // 插在表头
   {
     s->next=L;
     L=s; // 改变L
   }
   else
   { // 插在表的其余处
     while(p&&j<i-1) // 寻找第i-1个结点
     {
       p=p->next;
       j++;
     }
     if(!p) // i大于表长+1
       return ERROR;
     s->next=p->next;
     p->next=s;
   }
   return OK;
}

int ListDelete(LinkList &L,int i,ElemType &e)
{ // 在不带头结点的单链线性表L中，删除第i个元素，并由e返回其值
   int j=1;
   LinkList p=L,q;
   if(i==1) // 删除第1个结点
   {
     L=p->next; // L由第2个结点开始
     e=p->data;
     free(p); // 删除并释放第1个结点
   }
   else
   {
     while(p->next&&j<i-1) // 寻找第i个结点，并令p指向其前趋
     {
       p=p->next;
       j++;
     }
     if(!p->next||j>i-1) // 删除位置不合理
       return ERROR;
     q=p->next; // 删除并释放结点
     p->next=q->next;
     e=q->data;
     free(q);
   }
   return OK;
}
 
void ListTraverse(LinkList L,void(*vi)(ElemType))
{ // 初始条件：线性表L已存在。操作结果：依次对L的每个数据元素调用函数vi()
   LinkList p=L;
   while(p)
   {
     vi(p->data);
     p=p->next;
   }
   printf("\n");
}


int GetTop(LinkStack S,SElemType &e)
 { // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    /********** Begin **********/ 

    GetElem(S, 1, e); //栈是单链表的一种，相当于不带头节点的单链表，查找可直接调用单链表的函数
  //返回位置为1（栈顶）的数据元素，
    
    /********** End **********/	
}

int Push(LinkStack &S,SElemType e)
{ // 插入元素e为新的栈顶元素
    /********** Begin **********/ 
    
    ListInsert(S, 1, e);  //由于只是插入栈顶元素，故可以直接调用单链表的插入函数
    
    /********** End **********/	
 }

int Pop(LinkStack &S,SElemType &e)
{ // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    /********** Begin **********/ 
    
    ListDelete(S, 1, e); //由于只是删除栈顶元素，故也可以直接调用单链表的删除函数
    
    /********** End **********/	
 }

void StackTraverse(LinkStack S,void(*visit)(SElemType))
{ // 从栈底到栈顶依次对栈中每个元素调用函数visit()
    /********** Begin **********/ 
   
    LinkStack temp, p=S; //因为要求是从栈底到栈顶，故创建一个临时栈temp,把S中的数据元素Pop出来再Push进temp里，temp的数据元素排序就与原来S中的相反
    InitStack(temp); //初始化临时栈temp
    while(p)
    {
      Push(temp, p->data);
      p = p->next;
    }
    ListTraverse(temp, visit);


	  /********** End **********/	
}
