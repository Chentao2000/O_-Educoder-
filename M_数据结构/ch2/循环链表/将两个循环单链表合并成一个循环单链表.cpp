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
int ListInsert(LinkList &L,int i,int e) ;
void ListTraverse(LinkList L,void(*vi)(ElemType));
LinkList   merge_1(LinkList LA,LinkList LB);
int main()               //main() function 
{	
  LinkList A,B;
  ElemType e;
  InitList(A);
  InitList(B);
  int n,m,i;
  cin>>n;
  for(i=1;i<=n;i++)
  { 
    cin>>e;
    ListInsert(A, i, e);
  }
  cin>>m;
  for(i=1;i<=m;i++)
  { 
    cin>>e;
    ListInsert(B, i, e);
  }
  A=merge_1(A,B);
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

/*****循环单链表的基本操作*****/
void InitList(LinkList &L)
{ 
	// 构造一个空的循环单链表L
	L=(LinkList)malloc(sizeof(LNnode)); // 产生头结点，并使L指向此头结点
	if(!L) // 存储分配失败
		return ;
	L->next=L; // 指针域为L	
}
int ListInsert(LinkList &L,int i,ElemType e) 
{
	// 在带头结点的循环单链表L的第i个元素之前插入元素e  
	int j=1;
   LNnode *pre=L,*p=pre->next,*s;
   if (i<=0) return 0;	//参数i错误返回0
   while (p!=L && j<i)	//查找第i个结点p和其前驱结点pre
   {	
	j++;
	pre=p;
	p=p->next;	//pre、p同步后移一个结点
   }
   if (p==L && i>=j+1) return 0;//参数i>n+1时错误返回0
   else				//成功查找到第i个结点的前驱结点pre
   {	
	s=(LNnode *)malloc(sizeof(LNnode));
	s->data=e;		//创建新结点用于存放元素x
	s->next=pre->next;	//将s结点插入到pre结点之后
	pre->next=s;
	return 1;		//插入运算成功,返回1
   }
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

LinkList   merge_1(LinkList LA,LinkList LB)
{  
  //将两个采用头指针的循环单链表的首尾连接起来
  /********** Begin **********/ 
  LNnode *p, *q;
  p = LA;
  q = LB;
  while(p->next != LA)
  {
     p = p->next;
  }

  while(q->next != LB)
  {
     q = q->next;
  }
  q->next = LA; //LB的尾巴q要连接到LA的头结点
  p->next = LB->next; //LA的尾巴p要跳过LB连接到LB->next

   return(LA); //最后返回的是LA
  
  /********** End **********/
}
