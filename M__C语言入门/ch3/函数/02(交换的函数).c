#include <stdio.h>
void Swap(int* pa, int* pb)  //这样就是用函数交换地址来实现交换
{
    int tmp = 0;   
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}
int main()
{
    int a = 10;
    int b = 20;
    printf("a=%d,b=%d\n",a,b);
    Swap(&a, &b);   //用a和b的地址
    printf("a=%d,b=%d\n",a,b);
    return 0;
}
