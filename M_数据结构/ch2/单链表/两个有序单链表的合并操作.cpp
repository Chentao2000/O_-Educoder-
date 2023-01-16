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
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc);

int main()               //main() function 
{	
	LinkList A,B,C;
	ElemType e;
	InitList(A);
	InitList(B);
	int n,i;
	// cout<<"Please input the list number ";
	cin>>n;
	for(i=1;i<=n;i++)
	{ 
		cin>>e;
		ListInsert(A, i, e);
	}
	cin>>n;
	for(i=1;i<=n;i++)
	{ 
		cin>>e;
		ListInsert(B, i, e);
	}
	cout<<"合并两个有序单链表："<<endl;
	MergeList(A,B,C);	
	ListTraverse(C,output) ;	
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

void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc) 
{
	// 已知单链线性表La和Lb的元素按值非递减排列。
	// 归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列。
	/********** Begin **********/ 
    LinkList pa,pb,pc;
    pa = La->next; //pa为La的指针域
    pb = Lb->next; //pb为Lb的指针域
    pc = Lc = La;  //用La的头结点作为新链表Lc的头结点
    while(pa && pb) 
    {
        if(pa->data <= pb->data)
        {
            pc->next = pa; 
            pc = pa; 
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc -> next = pa?pa:pb;
	/********** End **********/
}
