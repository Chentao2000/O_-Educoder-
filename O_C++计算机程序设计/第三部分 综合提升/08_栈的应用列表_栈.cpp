#include "mstack.h"
// 函数empty：判断栈sk是否为空
// 参数：sk-栈
// 返回值：true-sk为空，false-sk不为空
bool empty(intStack sk)
{
    // 请在此添加代码，补全函数empty
    /********** Begin *********/
    return (listLength(sk) == 0); // 直接判断长度

    /********** End **********/
}
// 函数pop：弹栈
// 参数：sk-栈，传引用，弹栈可能会改变sk的值
// 返回值：弹栈的弹出的整数，如果栈空，返回-1
int pop(intStack &sk)
{
    // 请在此添加代码，补全函数pop
    /********** Begin *********/
    if (empty(sk))
        return -1;
    // 如果栈顶为 0

    int n = sk->data;
    // 获取栈顶结点（链首结点）的数据
    sk  = delAt(sk,0);// 0代表第一个的意思
    return n;



    /********** End **********/
}
// 函数push：压栈，将整数n压入栈sk中
// 参数：sk-栈，传引用，压栈会改变sk的值，n-要压栈的整数
// 返回值：无，采用链表实现栈，只要还有内存，压栈都会成功
void push(intStack &sk, int n)
{
    // 请在此添加代码，补全函数push
    /********** Begin *********/
    node *p = new node;
    p -> data= n;
    // 压栈(插入链首)
    sk = insertHead(sk,p);

    /********** End **********/
}
