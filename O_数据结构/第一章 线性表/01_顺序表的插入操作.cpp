#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define INIT_SIZE 5
#define INCREMENT 10
# define OK 1
# define ERROR 0
int MAXSIZE=100;
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
int ListInsert(SqList &L,int i,ElemType e);
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
	//cout<<"请输入插入的位置："<<endl;
	cin>>i;
	//cout<<"请输入插入的值："<<endl;
	input(e);
	if(  ListInsert(A,i,e) )
   {
        cout<<"插入成功，插入后顺序表如下："<<endl;
        ListTraverse(A,output) ;
    }
    else
    	cout<<"插入位置不合法，插入失败！"<<endl;
    return 0;
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
void InitList(SqList&L) {
    
    L.elem=new ElemType[MAXSIZE];
    if(!L.elem) exit(0);
    L.length=0;
    L.listsize=MAXSIZE;
}
int  ListInsert(SqList &L,int i,ElemType e)
{   // 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)+1
    // 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
    /********** Begin **********/ 
    if((i<1)||(i>L.length+1))  return 0;
    if(L.length==MAXSIZE)  return 0;
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    ++L.length;
    return 1;
    
    /********** End **********/
}
void ListTraverse(SqList L,void(*vi)(ElemType ) )
{   // 初始条件：顺序线性表L已存在
    // 操作结果：依次对L的每个数据元素调用函数vi()输出  
    /********** Begin **********/ 
    for(int i=0;i<L.length;i++)
    {
        cout<<L.elem[i]<<" ";
    }
    /********** End **********/
}
