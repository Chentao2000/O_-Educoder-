#include <stdio.h>
int main()
{
    int a = 10;
    int b = 20;
    int max = 0;
    max = a > b ? a : b; //exp1为a>b,如果a>b为真则max=a,如果a>b为假则max=b
    printf("%d\n", max);
    return 0;
}
