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

#define MAX_QSIZE 5 // 最大队列长度+1

struct SqQueue
{
   QElemType *base; // 初始化的动态分配存储空间
   int front; // 头指针，若队列不空，指向队列头元素
   int rear; // 尾指针，若队列不空，指向队列尾元素的下一个位置
};

void print(QElemType i)
{
   printf("%d ",i);
}
void InitQueue(SqQueue &Q); // 构造一个空队列Q
void DestroyQueue(SqQueue &Q); // 销毁队列Q，Q不再存在
void ClearQueue(SqQueue &Q); // 将Q清为空队列
int QueueEmpty(SqQueue Q); // 若队列Q为空队列，则返回TRUE；否则返回FALSE
int QueueLength(SqQueue Q); // 返回Q的元素个数，即队列的长度
int GetHead(SqQueue Q,QElemType &e); // 若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
int EnQueue(SqQueue &Q,QElemType e); // 插入元素e为Q的新的队尾元素
int DeQueue(SqQueue &Q,QElemType &e); // 若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR
void QueueTraverse(SqQueue Q,void(*vi)(QElemType)); // 从队头到队尾依次对队列Q中每个元素调用函数vi()  

int main()
{
   int j;
   int i=0,l;
   QElemType d;
   SqQueue Q;
   InitQueue(Q);
   for(i=0;i<MAX_QSIZE;i++)
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
/*struct SqQueue
{
   QElemType *base; // 初始化的动态分配存储空间
   int front; // 头指针，若队列不空，指向队列头元素
   int rear; // 尾指针，若队列不空，指向队列尾元素的下一个位置
};
*/
// 循环队列的基本操作(9个)
void InitQueue(SqQueue &Q)
{ // 构造一个空队列Q
   /********** Begin **********/ 

 	Q.base = (QElemType*)malloc(MAX_QSIZE*sizeof(QElemType)); //base指向新申请的空间
   Q.front = 0; //刚开始队头和队尾指针都为0
   Q.rear = 0;
    
	/********** End **********/  
}

void DestroyQueue(SqQueue &Q)
{ // 销毁队列Q，Q不再存在
   /********** Begin **********/ 
   free(Q.base); //释放base指向的空间
   Q.front = 0;  //队头和队尾指针都归0
   Q.rear = 0;
  
	/********** End **********/  
}

void ClearQueue(SqQueue &Q)
{ // 将Q清为空队列
    /********** Begin **********/ 
   Q.rear = Q.front; //当队头指针=队尾指针则为空队列

	/********** End **********/  
}

int QueueEmpty(SqQueue Q)
{ // 若队列Q为空队列，则返回TRUE；否则返回FALSE
   /********** Begin **********/ 
   if(Q.front == Q.rear) 
      return TRUE;
   else
      return FALSE;
	/********** End **********/  
 }

int QueueLength(SqQueue Q)
{ // 返回Q的元素个数，即队列的长度
   /********** Begin **********/ 
   int i = 0;
   i = (Q.rear - Q.front + MAX_QSIZE) % MAX_QSIZE; 
   return i;
	
//+MAX_QSIZE:目的是防止rear - front < 0
//%MAX_QSIZE:目的是防止当rear - front > 0时，又+ maxSize导致队列长度>maxSize

	/********** End **********/  
 }

 int GetHead(SqQueue Q,QElemType &e)
 { // 若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
   /********** Begin **********/ 
   if(Q.front==Q.rear) // 队列空则返回ERROR
     return ERROR;
   e=Q.base[Q.front]; //e返回队头元素
   return OK;
 /********** End **********/  
}

int EnQueue(SqQueue &Q,QElemType e)
{ // 插入元素e为Q的新的队尾元素
   /********** Begin **********/ 
   if((Q.rear+1) % MAX_QSIZE == Q.front) //队满则返回ERROR
      return ERROR;
   Q.base[Q.rear] = e; //新的队尾元素为e
   Q.rear = (Q.rear + 1) % MAX_QSIZE;  //指向下一个队尾元素
   return OK;
	/********** End **********/  
 }

int DeQueue(SqQueue &Q,QElemType &e)
{ // 若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR
   /********** Begin **********/ 
   if(Q.front == Q.rear) 
      return ERROR;
   e = Q.base[Q.front]; //返回队头元素
   Q.front = (Q.front + 1) % MAX_QSIZE; //删除队头元素即队头往下一位
   return OK;
	/********** End **********/  
}

void QueueTraverse(SqQueue Q,void(*vi)(QElemType))
{ // 从队头到队尾依次对队列Q中每个元素调用函数vi()
   /********** Begin **********/ 
   int i = Q.front;  //要求从队头开始，并且队尾上的数也要调用
   while((i + MAX_QSIZE) % MAX_QSIZE != Q.rear)  //当队头不等于队尾的时候//并且因为下面是i++，为了确保逻辑上的环状，故要使用该公式
   {					
      vi(Q.base[i]);
      i++;
   }
   printf("\n");
	/********** End **********/  
}
