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
int ListDelete(LinkList L,int i,ElemType &e);
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
	//cout<<"请输入删除的位置："<<endl;
	cin>>i;	
	if(  ListDelete(A,i,e) )
	{
		cout<<"删除成功，删除后单链表如下："<<endl;
		ListTraverse(A,output) ;
		cout<<"删除元素的值：";
	   output(e);
   	   cout<<endl;
	}
	else
		cout<<"删除位置不合法，删除失败！"<<endl;
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
{ 	// 构造一个空的单链表L	
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
{ 	// 调用函数vi()依次输出单链表L的每个数据元素
	LinkList p=L->next;
	while(p)
	{
		vi(p->data);
		p=p->next;
	}
	printf("\n");	
}

int  ListDelete(LinkList L,int i,ElemType &e) // 算法2.10。不改变L
{ 
	// 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
	/********** Begin **********/ 
    if(i<1)
        return 0;
    LinkList p=L;
    int j = 0; //j先指向头结点
    while(p && j<i-1) //没有到i之前，指针一直往后挪
    {
        p = p->next;
        j++;
    }
    if(!p || j>i-1) 
        return 0;
    if(p->next == NULL) //如果i位置上没有东西
        return 0;
    LinkList q = p->next; //q指向第i个位置
    e = q->data; //用e返回元素的值
    p -> next = q -> next; //为了让结点q从链中断开
    free(q); //释放q
    return 1;
	/********** End **********/
}
