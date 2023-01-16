#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/* 定义ElemType为int类型 */
typedef int ElemType;

/* 单链表类型定义 */
typedef struct LNnode
{	
	ElemType data;
	struct LNnode *next;
}LNnode,*LinkList;


void input(ElemType &s);
void output(ElemType s);
int equals(ElemType a,ElemType b);
int comp(ElemType a,ElemType b);

void InitList(LinkList &L);
int ListSortInsert (LinkList &L, ElemType e,int (*compare)(ElemType,ElemType));
void ListTraverse(LinkList L,void(*vi)(ElemType));
void ListDeleteSameNode(LinkList &L,int (*equals)(ElemType,ElemType));

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
 	ListDeleteSameNode(A, equals);
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
	L=(LinkList)malloc(sizeof(LNnode)); // 产生头结点，并使L指向此头结点
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
{ 	// 在带头结点的有序单链线性表L中插入元素e后仍然有序
	/********** Begin **********/ 
	 LNnode *curPtr ,*prePtr;
	int flag = 0;//检测是否成功插入；
	 LNnode *insPtr = (LNnode *)malloc(sizeof(LNnode));
	if(!insPtr) // 存储分配失败
		return 0;
	insPtr->data = e;
	curPtr = L->next;
	prePtr = L;
	while(curPtr)
	{
		if(compare(curPtr->data,  insPtr->data) > 0 )
		{
			prePtr->next = insPtr;
			insPtr->next = curPtr;
			flag = 1;
			break;
		}
		else
		{
			curPtr = curPtr->next;
			prePtr = prePtr->next;
		}
	}
	if(flag == 0)
	{
		prePtr->next = insPtr;
		insPtr->next = NULL;
	}
	return 1;
	/********** End **********/
}

void ListDeleteSameNode(LinkList &L,int (*equals)(ElemType,ElemType) )
{   // 在带头结点的有序单链线性表L中删除值相同的多余结点
	/********** Begin **********/ 
    LinkList pre,p,q;
    pre = L;
    p = L->next;
    while(p)
    {
        pre = p;
        p = p->next;
        if(p && equals(pre->data,p->data)==1)
        {
            pre->next = p->next;
            q = p;
            free(q);
            p = pre;
        }
    }
	/********** End **********/
}

