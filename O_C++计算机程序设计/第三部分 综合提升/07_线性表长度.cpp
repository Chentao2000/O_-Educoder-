#include "linearList.h"

int listLength(node * h)
{
    // 请在此添加代码，补全函数listLength
    /********** Begin *********/
    node *q = h;
    int count = 0;
    while(q){
        q = q->next;
        count++ ;
    }
    return count;

    /********** End **********/
}
