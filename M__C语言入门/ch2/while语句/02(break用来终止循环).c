#include <stdio.h>
int main()
{   
    int i = 0;
    while(i<10)
    {
        printf("%d\n", i);
        i++;
        if(i==5)
            break;      //break用来结束循环
    }
    return 0;
}
