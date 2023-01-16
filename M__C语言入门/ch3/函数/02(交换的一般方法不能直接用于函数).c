//一般的交换不能直接用于函数中，因为从空间来看，x、y和a、b毫无关系
#include <stdio.h>
void Swap(int x, int y)  //因为不用返回任何值，只是比较大小，故用void（空）
{
    int tmp = 0;  
    x = y;
    y = tmp;
}

int main()
{
    int a = 10;
    int b = 20;
    printf("a=%d,b=%d\n",a,b);
    Swap(a, b);
    printf("a=%d,b=%d\n",a,b);
    return 0;
}
//故输出前后结果一样
