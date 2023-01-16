
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/* 定义ElemType为int类型 */
typedef int ElemType;
void input(ElemType &s);
void output(ElemType s);
int equals(ElemType a,ElemType b);
int comp(ElemType a,ElemType b);

/* 单链表类型定义 */
typedef struct LNode
{	
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

void InitList(LinkList &L);
int ListSortInsert (LinkList &L, ElemType e,int (*compare)(ElemType,ElemType));
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
         ListSortInsert(A, e,comp);
      }
	 ListTraverse(A,output) ;
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
int comp(ElemType a,ElemType b)
{
	if(a>b)
		return  1;
	else
		if(a<b)
			return  -1;
		else
		return  0;
}


/*****单链表的基本操作*****/
void InitList(LinkList &L)
{ 
	// 操作结果：构造一个空的单链表L
	/********** Begin **********/ 
	L=(LinkList)malloc(sizeof(LNode)); // 产生头结点，并使L指向此头结点
	if(!L) // 存储分配失败
		return ;
	L->next=NULL; // 指针域为空
	/********** End **********/
}

void ListTraverse(LinkList L,void(*vi)(ElemType))
{ 
	// 初始条件：单链表L已存在。
	//操作结果：依次对L的每个数据元素调用函数vi()
	/********** Begin **********/ 
	LinkList p=L->next;
	while(p)
	{
		vi(p->data);
		p=p->next;
	}
	printf("\n");
	/********** End **********/
}

int ListSortInsert (LinkList &L, ElemType e,int (*compare)(ElemType,ElemType))
{ 
	/********** Begin **********/ 
    LinkList s,p,q;   //s,p,q三个指针
	s=(LinkList)malloc(sizeof(LNode)); //创建新结点，并用s来指向它
	if(!s) return 0; 
	s->data=e; //再把输入的e值给s
	if(L==NULL || comp(e,L->data)==-1) //如果L为空表，或者e的值比头结点的值小
    {
		s->next=L; //s放在头节点前面
		L=s; //再让s作为头结点
	}
    else
    {
		q=L; //q为头结点
		p=q->next; //p指向第一个数
		while(p!=NULL && compare(e,p->data)==1) //当p非空并且e的值大于p的值(就往下遍历)
        {
			q=p; // q代替p的位置
			p=p->next; //p指向下一个数
		}//遍历完后
		s->next=p; //s指向p
		q->next=s; //q指向s

	}
	return 1;  
	/********** End **********/
}
