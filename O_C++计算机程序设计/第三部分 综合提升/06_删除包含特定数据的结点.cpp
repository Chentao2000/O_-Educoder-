#include "linearList.h"

node * delHas(node * h, int n)
{
    // 请在此添加代码，补全函数delHas
    /********** Begin *********/
    node *p = NULL,*q = h;
    // 这里 *q =h 不是简单的赋值，而是直接q指向地址的 操作去了， q 的一切操作是会影响q 是会影响整个存储空间的
// 定位删除结点， 试图让q指向要删除的结点
// p 指向前面的结点 
    while(q->data != n){
        p = q;
        q=q->next;
    }
    if(p)
    {
        //删除 p 指向的结点 ，让p指向结点的指针域指向q的后续结点
        p->next = q ->next;
        delete q;
        return h ;
        
    }else //删除首节点的情况
        {
            h = q->next;
            delete q;
            return h;
        }

    /********** End **********/
}
