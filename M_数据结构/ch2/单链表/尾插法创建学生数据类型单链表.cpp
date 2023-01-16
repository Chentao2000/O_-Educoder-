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

/* 单链表类型定义 */
typedef struct LNnode
{	
	ElemType data;
	struct LNnode *next;
}LNnode,*LinkList;
void CreateTailList (LinkList  &L, ElemType  a[ ], int n ) ; //根据数组用头插法创建单链表 
void ListTraverse(LinkList L,void(*vi)(ElemType));

int  main()
{
    LinkList  head;          //定义一个LinkList 型的变量head
    ElemType  a[100];
    int n,i;
    scanf("%d",&n);
    for(i=0; i<n; i++ )                //遍历a数组所有元素
    {
        input(a[i]);
    }
    CreateTailList ( head,a,n);     //用尾插法输入数据创建单链表
    ListTraverse (head,output);         //输出以head为头的链表各结点的值  
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
  printf("出生日期:%d-%d-%d\t", s.birthday.year,s.birthday.month, s.birthday.day);
  printf("成绩:%.1f\n", s.score);
}


void ListTraverse(LinkList L,void(*vi)(ElemType))
{ 
	// 初始条件：单链表L已存在。
	//操作结果：依次对L的每个数据元素调用函数vi()
	/********** Begin **********/ 
	LinkList p=L->next;
	while(p)
	{
		vi(p->data);
		p=p->next;
	}
	printf("\n");
	/********** End **********/
}
void CreateTailList(LinkList  &L, ElemType  a[], int n)  
{
	//根据长度为n的数组a用尾插法来创建单链表L	 
	/********** Begin **********/ 
    LinkList node,p;
    p = L = (LinkList)malloc(sizeof(LNnode)); //p指针从L结点开始挪动
    L->next = NULL;
    for(int i=0;i<n;i++)
    {
        node = (LinkList)malloc(sizeof(LNnode));
        node->data = a[i];
        node->next = NULL; //新增加的结点在末尾，next要设为NULL
        p->next = node; //p指向node
        p = node; //p往后挪一位
    }
	/********** End **********/
}  
 
