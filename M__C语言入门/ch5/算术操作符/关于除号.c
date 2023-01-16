#include <stdio.h>
int main()
{
    int a = 5 / 2; //整数除法是不会得小数的
    double b = 5 / 2.0; //在除号两边随便一个数改成小数,就可以用浮点数来保存
    printf("%d\n", a);
    printf("%lf\n", b); //打印浮点数
    return 0;
}
