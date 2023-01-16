#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/* 定义学生数据类型STUDENT */
typedef struct date
{  
	int year;
	int month;
	int day;
}DATE;
typedef struct student
{
	int num;
	char name[20];
	char sex;
	DATE birthday;
	float score;
}STUDENT;

/* 定义ElemType为STUDENT类型 */
typedef STUDENT ElemType;

void input(ElemType &s);
void output(ElemType s);
int compare(ElemType a,ElemType b);
void swap(ElemType &a, ElemType &b);


/* 单链表类型定义 */
typedef struct LNnode
{	
	ElemType data;
	struct LNnode *next;
}LNnode,*LinkList;

void CreateHeadList(LinkList  &L, ElemType  a[ ], int n ) ; //根据数组用头插法创建单链表 
void ListTraverse(LinkList L,void(*vi)(ElemType));
void FstAndSndValue(LinkList  L, void(*vi)(ElemType), int (*compare)(ElemType,ElemType) ) ;

int  main()
{
	LinkList  head;          //定义一个LinkList 型的变量head
	ElemType  a[100 ];
	int n,i;
	scanf("%d",&n);
	for(i=0; i<n; i++ )                //输入数组所有元素
	{
		input(a[i]);
	}
	CreateHeadList ( head,a,n);        //用头插法输入数据创建单链表
	printf("所有学生信息:\n");
	ListTraverse (head,output);         //输出以head为头的链表各结点的值
	FstAndSndValue(head,output,compare);
	return 0; 
}
void input(ElemType &s)
{
	//printf("请输入学生学号:");
	scanf("%d",&(s.num));
	//printf("请输入学生姓名:");
	scanf("%s", s.name);
	//printf("请输入学生性别:");
	scanf(" %c",&(s . sex));
	//printf("请输入学生出生日期:");
	scanf("%d%d%d",&s.birthday.year, &s.birthday.month, &s. birthday.day);
	//printf("请输入学生成绩:");
	scanf("%f",&(s.score));	
}

void output(ElemType s)
{
	printf("学号:%d\t姓名:%s\t性别:%c\t", s.num,s.name,s.sex);
	printf("出生日期:%d-%d-%d \t", s.birthday.year,s.birthday.month, s.birthday.day);
	printf("成绩:%.1f\n", s.score);
}
int compare(ElemType a,ElemType b) 
{   // 如果要按照学生的成绩比较大小，则需根据a,b的score成员比较大小的结果，返回1、0、-1
	if ( a.score == b. score )
     	return 0;
   	else
    if( a. score < b. score )
     	return -1;
	else 
     	return 1;
}

void swap(ElemType &a, ElemType &b)
{
	ElemType t;
	t=a;a=b;b=t;
}


void ListTraverse(LinkList L,void(*vi)(ElemType))
{ 
	// 初始条件：单链表L已存在。
	//操作结果：依次对L的每个数据元素调用函数vi()
	LinkList p=L->next;
	while(p)
	{
		vi(p->data);
		p=p->next;
	}
	printf("\n");
}

void CreateHeadList(LinkList  &L, ElemType  a[], int n )  
{
	//根据长度为n的数组a用头插法来创建单链表L
	LNnode *p;          
	int i;  	         
	L =(LNnode *) malloc( sizeof(LNnode) ) ;  //创建头结点
	L ->next=NULL;      //头结点的next域置空，表示一个空单链表
	for(i=0; i<n; i++ )                //遍历a数组所有元素
	{
		p=(LNnode *)malloc(sizeof(LNnode));
		p->data=a[i];                   //创建存放a[i]元素的新结点p
		p->next=L->next;               //将p插在头结点之后
		L->next=p;        
	}  
} 

void  FstAndSndValue(LinkList  L, void(*vi)(ElemType), int (*compare)(ElemType,ElemType) ) 
{
	//在带头结点的单链表成查找成绩第一名和第二名学生的信息
	/********** Begin **********/ 
	STUDENT one ,two;
    int i = 1,a = 1,b; //a和b是用来分别记录第一名和第二名学生的信息位置
    one = L -> next -> data; //one就是第一个结点的值
    L = L->next->next; //L变为第二个结点
    while(L)
    {
        i++; //每往下一个值位置就要+1
        if(compare(L->data,one)>0) //当第二个结点大于第一个结点的值;当L的值大于第一名
        {
            two = one;  //two和one一样，都是第一个结点的值;现在第二名变为原来第一名
            b = a;  //b和a都为1; 现在第二名的位置变为原来第一名的位置
            one = L -> data; //one就变为第二个结点的值;one就变为L的值
            a = i; //a（第一名的位置）就＋1
        }
        else if(compare(L->data,two)>0) //当L和第一名比较后还大于第二名
        {
            two = L -> data; //第二名就为L的值
            b = i; //b（第二名的位置）就+1
        }
        L = L -> next ; //再继续往下一个值继续比较
    }
    
    printf("第%d个学生成绩是第一名：\n",a);
    vi(one);
    printf("\n");
    printf("第%d个学生成绩是第二名：\n",b);
    vi(two);
    //vi是一个回调函数。在调用时，可以把void visit(ElemType c)这个函数的指针当参数传入给函数ListTraverse_CL。比如,可以这么调用ListTraverse_CL(lp,visit);然后在ListTraverse_CL里调用visit这个函数，vi(p->data); 等于 visit(p->data);这里的visit可为input或output
	/********** End **********/
}
