#include <stdio.h>
int Add(int x, int y)
{
    int z = x + y;
    return z;
}
int main()
{
    int a = 100;
    int b = 200;
    int sum = 0;
    sum = Add(a, b);
    printf("%d\n",sum);
    return 0;
}
