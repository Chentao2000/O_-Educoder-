#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/* 定义ElemType为int类型 */
typedef int ElemType;
void input(ElemType &s);
void output(ElemType s);
int equals(ElemType a,ElemType b);
/* 单链表类型定义 */
typedef struct LNode
{	
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

void InitList(LinkList &L);
int ListInsert(LinkList &L,int i,int e) ;
void ListTraverse(LinkList L,void(*vi)(ElemType));

int main()               //main() function 
{	
     LinkList A;
     ElemType e;
     InitList(A);
      int n,i;
     // cout<<"Please input the list number ";
     cin>>n;
     for(i=1;i<=n;i++)
        { 
		   cin>>e;
         ListInsert(A, i, e);
       }
	//cout<<"请输入插入的位置："<<endl;
	cin>>i;
	//cout<<"请输入插入的值："<<endl;
	input(e);
	if(  ListInsert(A,i,e) )
    {
      cout<<"插入成功，插入后单链表如下："<<endl;
      ListTraverse(A,output) ;
    }
    else
    	cout<<"插入位置不合法，插入失败！"<<endl;
    return  0;  
 }


/*****ElemType类型元素的基本操作*****/
void input(ElemType &s)
{
cin>>s;
}
void output(ElemType s)
 {
cout<<s<<" ";
}
int equals(ElemType a,ElemType b)
{
	if(a==b)
		return  1;
	else
		return  0;
}

/*****单链表的基本操作*****/
void InitList(LinkList &L)
{ 
	// 操作结果：构造一个空的单链表L
	/********** Begin **********/ 
	L = (LinkList)malloc(sizeof(LNode)); //申请分配头结点，并使L指向此头结点
    if(!L) //如果存储分配失败
        return;
    L->next = NULL; //头结点指针域为空

	/********** End **********/
}
int ListInsert(LinkList &L,int i,int e) 
{
	// 在带头结点的单链线性表L的第i个元素之前插入元素e  
	/********** Begin **********/ 
    int j = 0;  //j记录p的指向的位置
    LinkList p=L,s; //定义p指针指向头结点（相当于L）和 定义指针s
    while(p && j<i-1) //当p还没有指到第i个元素时
    {
        p = p->next; //p指向下一个结点
        j++; //j也跟着记录p走的位置
    }
    if(!p || j>i-1) //如果i小于1或者大于表长
        return 0;
    s = (LinkList)malloc(sizeof(LNode)); //s指向新生成的结点
    s->data=e; //把e的值给s
    s->next=p->next; //p指向的下一个结点=s指向的下一个结点
    p->next=s; //p指向s
	/********** End **********/
}

void ListTraverse(LinkList L,void(*vi)(ElemType))
{ 
	// 初始条件：单链表L已存在。
	//操作结果：依次对L的每个数据元素调用函数vi()
	/********** Begin **********/ 
	LinkList p = L->next; //p指向单链表的第一个结点
    while(p)
    {
        vi(p -> data);  //用函数指针vi来实现对output()函数的调用
        p = p->next;
    }
	/********** End **********/
}
