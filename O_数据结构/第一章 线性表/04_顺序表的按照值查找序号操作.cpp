#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define INIT_SIZE 5
#define INCREMENT 10
# define OK 1
# define ERROR 0

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
void ListTraverse(SqList L,void(*vi)(ElemType ) );
int LocateElem(SqList L,ElemType e,int (*compare) (ElemType , ElemType));

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
	//cout<<"请输入查找的元素："<<endl;
	cin>>e;	
	i=LocateElem(A,e,equals);
	if( i ) 
	{
		cout<<"查找成功！"<<endl;		
	   output(e);
      cout<<endl;
		cout<<"是顺序表第"<<i<<"个元素"<<endl;
	}
	else
		cout<<"查找失败！"<<endl;
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


int LocateElem(SqList L,ElemType e,int (*compare) (ElemType , ElemType))
{
	// 初始条件：顺序表L已存在，compare()是数据元素判定函数(满足为1，否则为0)
	// 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
	// 若这样的数据元素不存在，则返回值为0。
	/********** Begin **********/ 
    ElemType *p;
    int i = 1;
    p = L.elem;
    while(i<=L.length &&!compare(*p++,e)){
        ++i;
    }
    if(i<=L.length)
    return i;
    else 
    return 0;
    /********** End **********/
	
}
