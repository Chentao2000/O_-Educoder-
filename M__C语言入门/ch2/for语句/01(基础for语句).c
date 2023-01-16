#include <stdio.h>
int main()
{
    int i = 0;
    for(i=1;i<10;i++)
    {
        if(i==5)
            break;         //和while语句一样有break和continue，性质也一样
        printf("%d\n", i);
    }
    return 0;
}
