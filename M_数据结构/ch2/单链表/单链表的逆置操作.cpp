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
typedef struct LNnode
{	
	ElemType data;
	struct LNnode *next;
}LNnode,*LinkList;
void InitList(LinkList &L);
int ListInsert(LinkList &L,int i,int e) ;
void ListTraverse(LinkList L,void(*vi)(ElemType));
void reverse (LinkList  L);
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
	cout<<"逆置单链表："<<endl;
	reverse(A);
	ListTraverse(A,output) ;	
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
{ 	// 操作结果：构造一个空的单链表L
	L=(LinkList)malloc(sizeof(LNnode)); // 产生头结点，并使L指向此头结点
	if(!L) // 存储分配失败
		return ;
	L->next=NULL; // 指针域为空	
}

int ListInsert(LinkList &L,int i,ElemType e) 
{	// 在带头结点的单链线性表L的第i个元素之前插入元素e  
	LinkList p,s;
	p = L;   
	int j = 0;
	while (p && j < i-1) {  // 寻找第i-1个结点
		p = p->next;
		++j;
	} 
	if (!p || j > i-1) 
		return 0;                   // i小于1或者大于表长
	s = (LinkList)malloc(sizeof(LNnode));  // 生成新结点
	s->data = e;  s->next = p->next;      // 插入L中
	p->next = s;
	return 1;	
}

void ListTraverse(LinkList L,void(*vi)(ElemType))
{ 	// 初始条件：单链表L已存在。
	//操作结果：依次对L的每个数据元素调用函数vi()
	LinkList p=L->next;
	while(p)
	{
		vi(p->data);
		p=p->next;
	}
	printf("\n");	
}

void reverse (LinkList  L)
{  
	//逆置L指针所指向的单链表
	/********** Begin **********/ 
    LinkList p,q;
    p = L->next; //p为头指针的指针域
    L->next = NULL; //头指针的指针域为NULL，因为刚开始一个结点都没有，故要初始化为空
    while(p) //当p不为空时（有数据时）
    {
        q=p; //p和q都指向第一个位置
        p=p->next; //p指向下一个位置
        q->next=L->next; //q指向的下一个结点=L指向的下一个结点（q指向p）
        L->next = q; //L指向q
    }
	/********** End **********/
}
