#include "mset.h"

// 函数unionSet：求集合a和b的并集
// 参数：a-集合，b-集合
// 返回值：集合（集合a和b的并集）
intSet unionSet(intSet a, intSet b)
{
    // 请在此添加代码，补全函数unionSet
    /********** Begin *********/
    intSet c = NULL;
    node *p =a,*q=b;
    while(p){
        addElement(c,p->data);
        p =p ->next;
    }

    while(q){
        addElement(c,q->data);
        q =q ->next;
    }
    return c;
 
    /********** End **********/
}
// 函数intersection：求集合a和b的交集
// 参数：a-集合，b-集合
// 返回值：集合（集合a和b的交集）
intSet intersection(intSet a, intSet b)
{
    // 请在此添加代码，补全函数intersection
    /********** Begin *********/

    intSet c = NULL;
    // 查看a中每一个元素
    node *p=a;
    while(p)
    {
        if(search(b,p->data))
        {// 也在b中，则选入集合c
            addElement(c,p->data);
        }
        p=p->next;
    }
    return c;


    /********** End **********/
}
// 函数addElement：在集合is中增加元素num
// 参数：is-集合，num-要增加的元素
// 返回值：无
void addElement(intSet &is, int num)
{
    // 请在此添加代码，补全函数addElement
    /********** Begin *********/
    node *p = search(is,num);
    if(p!=NULL)
        return ;
    p = new node ;
    p->data = num;
    p ->next = NULL;
    is = insertHead(is,p);

    /********** End **********/
}
