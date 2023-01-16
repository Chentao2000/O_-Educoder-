#include <stdio.h>
int main()
{
    int age = 10;
    if(age < 18)
    {
        printf("未成年\n");
        printf("多吃饭\n");  //这里就是多条语句(>=2条)，就要加上大括号
    }
    else
    {
        printf("成年人\n");
        printf("多睡觉\n");
    }
    return 0;
}
