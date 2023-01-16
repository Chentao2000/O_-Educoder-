#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/* 定义ElemType为int类型 */
typedef int ElemType;
void input(ElemType &s);
void output(ElemType s);
int equals(ElemType a,ElemType b);
/* 循环单链表类型定义 */
typedef struct LNnode
{	
	ElemType data;
	struct LNnode *next;
}LNnode,*LinkList;

void InitList(LinkList &L);
int ListInsert(LinkList &L,int i,ElemType e) ;
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
      cout<<"插入成功，插入后循环单链表如下："<<endl;
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

/*****循环单链表的基本操作*****/
void InitList(LinkList &L)
{ 
	// 构造一个空的循环单链表L
	L=(LinkList)malloc(sizeof(LNnode)); // 产生头结点，并使L指向此头结点
	if(!L) // 存储分配失败
		return ;
	L->next=L; // 指针域为L	
}
int ListInsert(LinkList &L,int i,int e) 
{
	// 在带头结点的循环单链表L的第i个元素之前插入元素e  
	/********** Begin **********/ 
    int j=1;
    LNnode *pre,*p,*s;
    pre = L;
    p = pre->next;
    if(i<=0)
        return 0;
    while(p!=L && j<i) //如果i超过表长，j还会一直加到最后一个结点，j最后会等于表长
    {
        j++; 
        pre=p;
        p = p->next;
    }
    if(i>=j+1)  //参数i>n+1时错误返回0，即i大于等于表长+1就不行，因为是要在第i个元素前插入，前提是有元素
        return 0;
    else
    {
        s=(LNnode*)malloc(sizeof(LNnode));
        s->data = e;
        s->next = pre->next;
        pre->next = s;
        return 1;
    }

	/********** End **********/
}

void ListTraverse(LinkList L,void(*vi)(ElemType))
{ 
	//依次对循环单链表L的每个数据元素调用函数vi()
	LNnode *p=L->next;
   while (p!=L)
   {	
		vi(p->data);
		p=p->next;
   }
   printf("\n");	
}
