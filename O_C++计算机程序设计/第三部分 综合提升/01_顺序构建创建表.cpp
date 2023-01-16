#include "linearList.h"

node *insertTail(node *h, node *t)
{
    // 请在此添加代码，补全函数insertTail
    /********** Begin *********/
    //  构建一个线性表 ，且函数返回值为插入节点后链表的首结点地址
    if(h == NULL)  // 空链表单独处理
    {
        t -> next = NULL;//空链表单独处理
        return t;// 返回第一结点的地址 (即链表头指针)
    }
    // 非空链表的情况
    node *p = h;
    // 让pp 指向最后一个节点
    while(p->next)
        p = p ->next;
    // 如果指向的不是尾巴，就一直指下去

    p -> next = t;
    t -> next = NULL;
    // 指向尾巴
    return h;
    

    /********** End **********/
}
