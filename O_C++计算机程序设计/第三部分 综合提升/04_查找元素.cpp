#include "linearList.h"

node * search(node * h, int num)
{
    // 请在此添加代码，补全函数search
    /********** Begin *********/
    while(h){
        // h 为真 ，即h指向 结点存在 
        if(h->data == num)
            return h;
        h = h->next ;
        // 将该节点的指针域赋给h h就指向下一个节点了

    }
    return NULL;


    /********** End **********/
}
