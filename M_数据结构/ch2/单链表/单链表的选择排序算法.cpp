#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/* 定义ElemType为int类型 */
typedef int ElemType;
void input(ElemType &s);
void output(ElemType s);
void swap(ElemType &a,ElemType &b);

/* 单链表类型定义 */
typedef struct LNnode
{	
	ElemType data;
	struct LNnode *next;
}LNnode,*LinkList;
void InitList(LinkList &L);
int ListInsert(LinkList &L,int i,int e) ;
void ListTraverse(LinkList L,void(*vi)(ElemType));
void SelectedSort(LinkList L);  //单链表的选择排序算法

int main()              
{	
    LinkList  head;          //定义一个LinkList 型的变量head
    ElemType  a[100 ];
    int n,i;
    scanf("%d",&n);
    for(i=1; i<=n; i++ )                //输入数组所有元素
    {
        input(a[i]);
    }
    InitList(head);
    for(i=1;i<=n;i++)     //将数组元素插入到单链表head中
    { 
        ListInsert(head, i, a[i]);
    }
    SelectedSort(head);
    return 0;  
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
void swap(ElemType &a,ElemType &b)
{
    ElemType t;
    t=a; a=b;b=t;		
}

/*****单链表的基本操作*****/
void InitList(LinkList &L)
{ 
	// 操作结果：构造一个空的单链表L
	L=(LinkList)malloc(sizeof(LNnode)); // 产生头结点，并使L指向此头结点
	if(!L) // 存储分配失败
		return ;
	L->next=NULL; // 指针域为空
}
int ListInsert(LinkList &L,int i,int e) 
{	// 在带头结点的单链线性表L的第i个元素之前插入元素e  
	LinkList p,s;
	p = L;   
	int j = 0;
	while (p && j < i-1) 
	{  // 寻找第i-1个结点
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


void SelectedSort(LinkList L) 
{	//用选择排序算法将带头结点的单链表排成一个有序的单链表
	/********** Begin **********/ 
	LNnode *p=L->next,*q,*min; 
	while(p)
	{
		q=p->next; 
		min=p; 
		while(q)
		{
			if(q->data<min->data)
				min=q;
			q=q->next;
		}
	    if(min!=p)
	    {
		    swap(min->data,p->data);
	    }
	    p=p->next;
        ListTraverse(L, output);
	}

	/********** End **********/
}
