#include <stdio.h>
//宏的定义
#define MAX(X, Y) (X>Y?X:Y) //如求最大值用宏更简洁
int main()
{
    int a = 10;
    int b = 20;
    int max = MAX(a, b);
    printf("%d\n", max);
    return 0;
}
