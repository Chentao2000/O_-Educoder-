#include <stdio.h>
int main()
{   
    int i = 1;
    while(i<10)
    {
        if(i==5)
            continue;       //continue后面的代码不执行，直接进入下一个循环
        printf("%d\n", i);
        i++;
    }
    return 0;
}
