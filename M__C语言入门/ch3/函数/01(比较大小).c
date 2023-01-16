#include <stdio.h>
int MAX(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}
int main()
{
    int a = 10;
    int b = 20;
    int res = 0;
    res = MAX(a, b);
    printf("%d\n", max);
    return 0;
}
