#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define INIT_SIZE 5
#define INCREMENT 10

/* 定义ElemType为int类型 */
typedef int ElemType;
void input(ElemType &s);
void output(ElemType s);
int equals(ElemType a,ElemType b);

/* 顺序表类型定义 */
typedef  struct
{
	ElemType *elem; 	//存储空间基地址
	int 	length; 	//当前长度
	int  listsize; 	//当前分配的存储容量
}SqList;

void InitList(SqList&L); 
int  ListInsert(SqList &L,int i,ElemType e);
int  ListDelete(SqList &L,int i,ElemType&e) ;
void ListTraverse(SqList L,void(*vi)(ElemType ) );

int main()               //main() function 
{	
	SqList A;
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
		cout<<"删除成功，删除后顺序表如下："<<endl;
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

/*****顺序表的基本操作*****/

void InitList(SqList&L) 
{	// 操作结果：构造一个空的顺序线性表L
 	/********** Begin **********/ 
	L.elem=(ElemType*)malloc( INIT_SIZE*sizeof(ElemType));
	if(!L.elem)
		return; // 存储分配失败
	L.length=0; // 空表长度为0
	L.listsize=INIT_SIZE; // 初始存储容量
	/********** End **********/
}


int  ListInsert(SqList &L,int i,ElemType e)
{	// 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)+1
	// 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
	/********** Begin **********/ 
	ElemType *newbase,*q,*p;
	if(i<1||i>L.length+1) // i值不合法
		return 0;
	if(L.length>=L.listsize)
    { // 当前存储空间已满，增加分配
		if(!(newbase=(ElemType*)realloc(L.elem,(L.listsize+INCREMENT)*sizeof(ElemType))))
			return(0); ; // 存储分配失败
		L.elem=newbase; // 新基址
		L.listsize+= INCREMENT; // 增加存储容量
	}
	q=L.elem+i-1; // q为插入位置
	for(p=L.elem+L.length-1;p>=q;--p) // 插入位置及之后的元素右移
		*(p+1)=*p;
	*q=e;            // 插入e
	++L.length;      // 表长增1
	return 1;
	/********** End **********/
}

void ListTraverse(SqList L,void(*vi)(ElemType ) )
{ 
	// 初始条件：顺序线性表L已存在
	// 操作结果：依次对L的每个数据元素调用函数vi()输出
	/********** Begin **********/ 
	ElemType *p;
	int i;
	p=L.elem;
	for(i=1;i<=L.length;i++)
		vi(*p++);
	printf("\n");
	/********** End **********/
}

int  ListDelete(SqList &L,int i,ElemType&e) 
{
	// 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)
	// 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
	/********** Begin **********/ 
    e = L.elem[i-1];
	if(i<1 || i>L.length)
        return 0;
    for(int j = i; j <= L.length-1; j++)
        L.elem[j-1] = L.elem[j];
    L.length--;

	/********** End **********/
}

