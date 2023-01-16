#include <stdio.h>
int main()
{
    int a = 10; 
    int* p = &a; //p为指针变量，类型为int*
    printf("%p\n", p); //%p用来打印地址
    *p = 20; //*为解引用操作符，即可找到a且把a变为20
    printf("%d\n", a);
    return 0;
}
