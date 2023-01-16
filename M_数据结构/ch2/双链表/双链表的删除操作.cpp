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
int ListDelete(DLinkList L,int i,ElemType &e);
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
	//ListTraverse(A,output) ;
	//cout<<"请输入删除的位置："<<endl;
	cin>>i;
	if(  ListDelete(A,i,e) )
	{
		cout<<"删除成功，删除后双向链表如下："<<endl;
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

/*****双向链表的基本操作*****/
void InitList(DLinkList &L)
{ 	//构造一个空的双向链表L
	L=(DLinkList)malloc(sizeof(DLinkNode)); // 产生头结点，并使L指向此头结点
	L->next=NULL; // 指针域为空
	L->prior=NULL; 	
}

int ListInsert(DLinkList &L,int i, ElemType e) 
{
	// 在带头结点的双向链表L的第i个元素之前插入元素e  
	int j=0;
	DLinkNode *p=L,*s;
	if (i<=0) return 0;	      //参数i错误返回0
	while (p!=NULL && j<i-1)	   //查找第i-1个结点p
	{	
		j++;
		p=p->next;
	}
   if (p==NULL) 
		return 0;	   //未找到返回0
   else
   {	
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=e;		//创建一个存放元素x的新结点
        s->next=p->next;	//对应插入操作的步骤①
        if (p->next!=NULL)	//对应插入操作的步骤②
        p->next->prior=s;
        s->prior=p;		//对应插入操作的步骤③
        p->next=s;		//对应插入操作的步骤④
        return 1;		//插入运算成功,返回1
    }
	
}

void ListTraverse(DLinkList L,void(*vi)(ElemType))
{ 
	// 输出带头结点的双向链表L的每个元素 
	DLinkList p=L->next;
	while(p)
	{
		vi(p->data);
		p=p->next;
	}
	printf("\n");	
}

int  ListDelete(DLinkList L,int i,ElemType &e)    // 不改变L
{ 
	// 在带头结点的双向链表L中，删除第i个元素，并由e返回其值
	/********** Begin **********/
    int j = 1; 
	DLinkList pre,p;
    pre = L;
    p = pre->next;
    p->prior = pre;
    if(i<=0)
        return 0;
    while(p->next != NULL && j<i)
    {
        pre = p;
        p = p->next;
        j++;
    }
    if(i>j)
        return 0;
    else
    {
        e = p->data;
        if(p->next != NULL)
        {
            p->next->prior = pre;
            pre->next = p->next;
            free(p);
        }
        else
        {
            pre->next = NULL;
            free(p);
        }
        return 1;
    }

    


	/********** End **********/
}

