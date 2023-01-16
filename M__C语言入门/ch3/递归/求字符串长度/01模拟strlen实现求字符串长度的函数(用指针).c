//《编写函数不允许创建临时变量，求字符串长度》的铺垫
//arr是数组，数组传参，传过去的不是整个数组，而是第一个元素的地址
//arr在给函数my_strlen传参时，传的是地址，故最后设计函数时，char后要带*号，str是变量名 -> my_strlen(char* str)
#include <stdio.h>
int my_strlen(char* str) //接收arr传来的第一个元素的地址，此时得到指针变量*str
{
    int count = 0;       //创建临时变量count
    while(*str != '\0')  //只要指针还没有指到字符串数组的最后一个隐藏元素‘\0’，就继续循环
    {
        count++; //数量+1
        str++;  //指针往后+1，指向下一个元素
    }
    return count; //返回整型count 
}
int main()
{
    char arr[] = "bit"; //字符串数组
    int len = my_strlen(arr);
    printf("len = %d\n", len);
    return 0;
}
