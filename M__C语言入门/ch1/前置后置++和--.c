#include <stdio.h>
int main()
{
    int a = 10;
    int b = a++;
    //int b = ++a;
    //int b = a--;
    //int b = --a;
    printf("%d\n%d\n", a, b);
    return 0;
}
