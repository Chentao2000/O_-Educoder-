#include <stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0 
 #define OVERFLOW -1
 typedef int QElemType;
 
typedef struct QNode
{
   QElemType data;
   QNode *next;
}*QueuePtr;
struct LinkQueue
{
   QueuePtr front,rear; // 队头、队尾指针
};

void print(QElemType i)
{
   printf("%d ",i);
}
void InitQueue(LinkQueue &Q); // 构造一个空队列Q
void DestroyQueue(LinkQueue &Q); // 销毁队列Q，Q不再存在
void ClearQueue(LinkQueue &Q); // 将Q清为空队列
int QueueEmpty(LinkQueue Q); // 若队列Q为空队列，则返回TRUE；否则返回FALSE
int QueueLength(LinkQueue Q); // 返回Q的元素个数，即队列的长度
int GetHead(LinkQueue Q,QElemType &e); // 若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
int EnQueue(LinkQueue &Q,QElemType e); // 插入元素e为Q的新的队尾元素
int DeQueue(LinkQueue &Q,QElemType &e); // 若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR
void QueueTraverse(LinkQueue Q,void(*vi)(QElemType)); // 从队头到队尾依次对队列Q中每个元素调用函数vi()

int main()
{
   int j;
   int i=0,l;
   QElemType d;
   LinkQueue Q;
   InitQueue(Q);
   for(i=0;i<5;i++)
   {
     scanf("%d",&d);     
     EnQueue(Q,d);
   };
   printf("队列长度为: %d\n",QueueLength(Q));
   printf("现在队列中元素:\n");
   QueueTraverse(Q,print);
   DeQueue(Q,d);
   printf("删除的元素是%d\n",d);
   DeQueue(Q,d);
   printf("删除的元素是%d\n",d);
   scanf("%d",&d);
   EnQueue(Q,d);
    printf("队列长度为: %d\n",QueueLength(Q));
   printf("现在队列中元素:\n");
   QueueTraverse(Q,print);
   j=GetHead(Q,d);
   if(j)
     printf("现在队头元素为:%d\n",d);
   ClearQueue(Q);
   DestroyQueue(Q);
 }
/*typedef struct QNode
{
   QElemType data;
   QNode *next;
}*QueuePtr;
struct LinkQueue
{
   QueuePtr front,rear; // 队头、队尾指针
};
*/

// 链队列的基本操作(9个)
void InitQueue(LinkQueue &Q)
 { // 构造一个空队列Q
  /********** Begin **********/ 
  Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode)); //生成头结点
  Q.front->next = NULL; //确保为空队列
 
  /********** End **********/  
}

void DestroyQueue(LinkQueue &Q)
{ // 销毁队列Q(无论空否均可)
   /********** Begin **********/ 
  while(Q.front)
  {
    Q.rear = Q.front->next;  //队尾指针设为队头的下一个
    free(Q.front);  //释放头结点指向的空间
    Q.front = Q.rear; //新的队头指针等于队尾指针
  }


  /********** End **********/  
}

void ClearQueue(LinkQueue &Q)
{ // 将Q清为空队列
	/********** Begin **********/ 

  Q.front->next = NULL;

	/********** End **********/  
 }

int QueueEmpty(LinkQueue Q)
 { // 若Q为空队列，则返回TRUE，否则返回FALSE
   /********** Begin **********/ 

  if(Q.front == Q.rear)
  {
    return TRUE;
  }
  else
    return FALSE;

	/********** End **********/  
}

int QueueLength(LinkQueue Q)
{ // 求队列的长度
   /********** Begin **********/ 
  int len = 0;
  QueuePtr p = Q.front->next; //p用来记录指针位置
  while(p)
  {
    len++;
    p=p->next;
  }
  return len;
	/********** End **********/  
}

int GetHead(LinkQueue Q,QElemType &e)
{ // 若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
   /********** Begin **********/ 
  QueuePtr p; //用p向队头元素并返回
  if(Q.front == Q.rear)
  {
    return ERROR;
  }
  p = Q.front->next; //因为front是头指针，所以p现在指向第一个
  e = p->data; //e返回队头元素
  return OK;
	/********** End **********/  
 }

int EnQueue(LinkQueue &Q,QElemType e)
{ // 插入元素e为Q的新的队尾元素
  /********** Begin **********/ 
  QueuePtr p; //用p指向新的结点
  p = (QueuePtr)malloc(sizeof(QNode)); 
  p->data = e;    //将e的值赋给新结点
  p->next = NULL;  //新节点的指针为空
  Q.rear->next = p; //原队尾结点的指针指向新结点
  Q.rear = p; //队尾指针指向新结点
  /********** End **********/  
}

int DeQueue(LinkQueue &Q,QElemType &e)
{ // 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR
  /********** Begin **********/ 
  QueuePtr p; //用p指向要删除的队头元素，并把值给e
  if(Q.front == Q.rear) 
    return ERROR;
  p = Q.front->next;
  e = p->data;
  Q.front->next = p->next;
  if(Q.rear==p)
    Q.rear = Q.front;
  free(p);
  return OK;
  /********** End **********/  
}

void QueueTraverse(LinkQueue Q,void(*vi)(QElemType))
{ // 从队头到队尾依次对队列Q中每个元素调用函数vi()
  /********** Begin **********/ 
  QueuePtr p = Q.front->next;
  while(p)
  {
    vi(p->data);
    p = p->next;
  }
  printf("\n");

	/********** End **********/  
 }
