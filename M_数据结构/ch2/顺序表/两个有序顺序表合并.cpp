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
void ListTraverse(SqList L,void(*vi)(ElemType ) );
int MergeList(SqList La, SqList Lb, SqList &Lc) ;

int main()               //main() function 
{	
	SqList A,B,C;
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
	cout<<"合并两个有序顺序表："<<endl;
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


int MergeList(SqList La, SqList Lb, SqList &Lc) 
{  
	// 已知顺序线性表La和Lb的元素按值非递减排列。
	// 归并La和Lb得到新的顺序线性表Lc，Lc的元素也按值非递减排列。
	/********** Begin **********/ 
     Lc.length = La.length + Lb.length; //Lc的长度
     Lc.elem = new ElemType[Lc.length]; //为新表分配一个数组空间
     int *pa = La.elem;  
     int *pb = Lb.elem;
     int *pc = Lc.elem;

     int *pa_last = La.elem + La.length -1;  
     int *pb_last = Lb.elem + Lb.length -1;

     while((pa <= pa_last) && (pb <= pb_last))
     {
         if(*pa <= *pb)
            *pc++ = *pa++ ;
         else
            *pc++ = *pb++;
     }
     while(pa<=pa_last)
        *pc++ = *pa++;
     while(pb<=pb_last)
        *pc++ = *pb++;
	/********** End **********/
}

