#include <stdio.h>
int main()
{
    int i = 1;
    do              //先直接执行do后面再根据while的表达式来判断是否进入下一个循环
    {
        if(i==5)
            break;  //彻底结束do...while循环
        printf("%d\n", i);
        i++;
    }
    while(i<=10);   //注意分号
    return 0;
}
