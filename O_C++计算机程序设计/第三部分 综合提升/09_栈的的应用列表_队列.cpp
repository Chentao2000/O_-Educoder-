#include "mqueue.h"

// 函数queueEmpty：判断队列iq是否为空
// 参数：iq-整数队列
// 返回值：true-队列iq为空，false-iq不为空
bool queueEmpty(intQueue iq)
{
    // 请在此添加代码，补全函数queueEmpty
    /********** Begin *********/ 
   return (listLength(iq) == 0);


    /********** End **********/
}
// 函数enQueue：将整数num入列到iq
// 参数：iq-整数队列，传引用，入列有可能改变队列头指针，num-入列的整数
// 返回值：无，只要还有内存，入列总会成功
void enQueue(intQueue &iq, int num)
{
    // 请在此添加代码，补全函数enQueue
    /********** Begin *********/
     node *p =new node;
     p->data = num;
     p->next= NULL;
     iq = insertTail(iq,p);


    /********** End **********/
}
// 函数deQueue：出列
// 参数：iq-整数队列，传引用，出列有可能改变队列头指针
// 返回值：出列结点的数据，如果队列为空，返回-1
int deQueue(intQueue &iq)
{
    // 请在此添加代码，补全函数deQueue
    /********** Begin *********/
    if (queueEmpty(iq))
        return -1;
    
    int n = iq->data;
    
    iq = delAt(iq,0);
    return n;


    /********** End **********/
}
