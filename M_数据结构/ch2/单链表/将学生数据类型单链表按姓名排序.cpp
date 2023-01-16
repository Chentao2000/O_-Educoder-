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
void BubbleSort(LinkList  &head,int (*compare)(ElemType,ElemType));

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
	printf("排序前:\n");
	ListTraverse (head,output);         //输出以head为头的链表各结点的值
	BubbleSort(head,compare);
	printf("排序后:\n");
	ListTraverse (head,output); 
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
{   // 如果要按照学生的姓名比较大小，则需根据a,b的name成员比较大小的结果，返回1、0、-1
	if (  strcmp( a.name, b.name ) > 0 )
		return 1;
	else  if ( strcmp( a.name, b.name ) == 0 )
		return 0;
	else 
		return -1;   
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

void BubbleSort(LinkList  &head,int (*compare)(ElemType,ElemType))
{
	//用冒泡法将带头结点的单链表排成一个有序的单链表
	/********** Begin **********/ 
    //也就是比较姓名中字符串的大小
	LinkList p1,p2;
    p1 = head->next;
    while(p1)
    {
        p2 = p1 -> next;
        while(p2)
        {
            if(compare(p1->data,p2->data)>0) //当p1的字符串大小＞p2的字符串大小时
            {
                swap(p1->data,p2->data); //交换
            }
            p2 = p2 -> next; 
        }
        p1 = p1 -> next;
    }

	/********** End **********/
}
