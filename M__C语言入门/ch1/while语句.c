#include <stdio.h>
int main()
{
    int line = 0;
    while(line<20000)
    {
        printf("hi~%d\n", line);
        line++;
    }
    printf("yes!\n");
    return 0;
}
