//          n<=1  ->  1
//Fac(n)
//          n>1   ->  n*Fac(n-1)
#include <stdio.h>
int Fac(int n)
{
    if(n<=1)
        return 1;
    else
        return n*Fac(n-1);
}
int main()
{
    int n = 0;
    int res = 0;
    scanf("%d", &n);
    res = Fac(n);
    printf("%d\n", res);
    return 0;
}
