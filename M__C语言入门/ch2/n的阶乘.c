#include <stdio.h>
int main()
{
    int i = 0;
    int n = 0;
    int res = 1;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        res = res * i;
    }
    printf("%d\n", res);
    return 0;
}
