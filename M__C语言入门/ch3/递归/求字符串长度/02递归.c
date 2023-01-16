//《编写函数不允许创建临时变量，求字符串长度》
//把大事化小
//my_strlen("bit")
//1+my_strlen("it")
//1+1+my_strlen("t")
//1+1+1+my_strlen("")
//1+1+1+0
//3
#include <stdio.h>
int my_strlen(char* str) 
{
    if(*str != '\0')
        return 1+my_strlen(str+1); //str+1也就是指针往后挪一位
    else
        return 0;
}

int main()
{
    int len = 0;
    char arr[] = "bit";
    len = my_strlen(arr);
    printf("%d\n", len);
    return 0;
}
