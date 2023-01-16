#include <stdio.h>
int main()
{   
    int n = 1;
    int m = 2;
    switch (n)
    {
        case 1:m++;
        case 2:n++;
        case 3:
            switch (n)          //switch可以嵌套使用
            {
                case 1:n++;
                case 2:m++;n++;break;
            }
        case 4:m++;
        default:
            break;
    }
    printf("%d\n%d\n",m, n);
    return 0;
}
