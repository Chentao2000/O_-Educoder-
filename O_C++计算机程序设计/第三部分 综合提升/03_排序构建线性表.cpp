#include "linearList.h"
node * insertSort(node *h, node *t)
{
    // 请在此添加代码，补全函数insertSort
    /********** Begin *********/
    node *p = NULL, *q = h;  // 定位第一个插入点：链首
    // 查找插入点
    while(q && q->data < t->data)
    {// 两个指针并行后移
        p = q;
        q = q->next;
    }
    // 插入链首
    if(p == NULL)
    {
        t->next = h;
        return t;
    }
    // 插入链尾
    if(q == NULL)
    {
        p->next = t;
        t->next = NULL;
    }
    // 插入p、q之间
    t->next = q;
    p->next = t;
    return h;
    /********** End **********/
}
