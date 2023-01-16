#include <stdio.h>
int main()
{
    int a = 0; //0
    int b = 5; //非0
    int c = a&&b; //逻辑与&&
    int d = a||b; //逻辑或||
    printf("%d\n%d\n", c, d);
    return 0;
} 
