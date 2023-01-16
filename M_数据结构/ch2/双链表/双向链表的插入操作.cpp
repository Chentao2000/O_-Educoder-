#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/* 定义ElemType为int类型 */
typedef int ElemType;
void input(ElemType &s);
void output(ElemType s);
int equals(ElemType a,ElemType b);

/* 双向链表类型定义 */
typedef struct node
{  ElemType data;		//数据域
   struct node *prior,*next;	//分别指向前驱结点和后继结点的指针
} DLinkNode,*DLinkList;

void InitList(DLinkList &L);
int ListInsert(DLinkList &L,int i, ElemType e) ;
void ListTraverse(DLinkList L,void(*vi)(ElemType));

int main()               //main() function 
{	
     DLinkList A;
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
      cout<<"插入成功，插入后双向链表如下："<<endl;
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

/*****双向链表的基本操作*****/
void InitList(DLinkList &L)
{ 	//构造一个空的双向链表L
	/********** Begin **********/ 
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
    L->prior = L->next = NULL;
	/********** End **********/	
}
int ListInsert(DLinkList &L,int i, ElemType e) 
{
	// 在带头结点的双向链表L的第i个元素之前插入元素e  
	/********** Begin **********/ 
	DLinkNode *p,*s;
    p = L;
    int j=1;
    if(i<=0)
        return 0;
    while(p->next!=NULL && j<i)
    {
        j++;
        p=p->next;
    }
    if(i>=j+1)
        return 0;
    else
    {
        s=(DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = e;
        s->next = p->next;
        if(p->next != NULL)
            p->next->prior = s;
        s->prior = p;
        p->next = s;
        return 1;
    }
	/********** End **********/
}

void ListTraverse(DLinkList L,void(*vi)(ElemType))
{ 
	// 输出带头结点的双向链表L的每个元素 
	/********** Begin **********/ 
	DLinkNode *p;
    p = L;
    while(p->next != NULL)
    {
        p = p->next;
        vi(p->data);
    }
    printf("\n");
    
	/********** End **********/
}
