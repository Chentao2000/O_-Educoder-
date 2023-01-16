#include <stdio.h>
//用extern声明外部函数
extern int Add(int, int); //声明函数返回类型为int，第一个参数类型为int，第二个参数类型为int => 即可调用01.c的Add函数
int main()
{
    int a = 10;
    int b = 20;
    int sum = Add(a, b);
    printf("%d\n", sum);
    return 0;
}
