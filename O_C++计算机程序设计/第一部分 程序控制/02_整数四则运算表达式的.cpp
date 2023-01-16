//包含标准输入输出函数库
#include <stdio.h>

int main()
{
    //声明两个整型变量，用于存储输入的两个整数
    int x,y;
    //请在Begin-End之间添加你的代码，按要求格式输出四则运算式子
    /********** Begin *********/
        int s, d, p, c;
    scanf("%d", &x);
    scanf("%d", &y);
    s = x + y;
    d = x - y;
    p = x * y;
    c = x / y;
    printf("%5d + %-5d = %10d\n", x, y, s);
    printf("%5d - %-5d = %10d\n", x, y, d);
    printf("%5d * %-5d = %10d\n", x, y, p);
    printf("%5d / %-5d = %10d\n", x, y, c);
    
    /********** End **********/
    return 0;
}
