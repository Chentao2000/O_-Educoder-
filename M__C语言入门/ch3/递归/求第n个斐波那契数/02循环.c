//用循环更快，仅需移动a、b、c，最后的c即为结果
#include <stdio.h>
int Fib(int n)
{
    int a = 1;
    int b = 1;
    int c = 2;
    while(n>2)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}

int main()
{
    int n = 0;
    int res = 0;
    scanf("%d", &n);
    res = Fib(n);
    printf("%d\n", res);
    return 0;
}
