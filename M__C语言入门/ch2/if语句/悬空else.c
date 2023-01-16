#include <stdio.h>
int main()
{
    int age = 90;
    if(age == 100)
        if(age==0)
            printf("wawa");
    else                      //C语言中的else只与它上一个最近的if匹配，不看缩进！
        printf("nono");       //所以这个else是上面的那个if（age==0）的
    return 0;                 //因为if（age==100）已经不符合条件了，所以下面的if和else不会执行，故没有输出
}
