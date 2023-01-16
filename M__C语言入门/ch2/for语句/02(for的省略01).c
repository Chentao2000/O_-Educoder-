#include <stdio.h>

int main()
{
    for(;;)   //for循环的初始化、调整、判断都可以省略，都被省略时，判断条件是恒为真
    {
        printf("hi"); //所以这个hi会一直循环下去
    }
    return 0;
}
