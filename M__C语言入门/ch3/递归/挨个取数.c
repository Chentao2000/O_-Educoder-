//接受一个整型值（无符号），按照顺序打印它的每一位，例如输入1234,则输出1 2 3 4 
//把大事化小
//1234      Print(1234)   
//123 4     Print(1234) -> 4
//12 3 4    Print(123)  -> 3
//1 2 3 4   Print(12)   -> 2
//1 2 3 4   Print(1)    -> 1
//由于递归由最里层函数开始执行，故输出为1 2 3 4

#include <stdio.h>
int Print(int n) //例如输入1234
{
    if(n>9)    //如果大于一位数
    {
        Print(n/10); // n/10即除10取整
    }
    printf("%d ", n%10); //打印余数，即最后一个数
}
int main()
{
    unsigned int num = 0;
    scanf("%d", &num);
    Print(num);
    return 0;
}
