#include <stdio.h>
int main()
{
    int a = 10;
    int b = 20;
    int tmp = 0;   //用tmp把原来的a存起来
    printf("a=%d,b=%d\n",a,b);
    tmp = a;
    a = b;
    b = tmp;
    printf("a=%d,b=%d\n",a,b);
    return 0;
}
