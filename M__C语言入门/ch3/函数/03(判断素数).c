//写一个函数可以判断一个数是不是素数
 #include <stdio.h>
 #include <math.h>
 int is_prime(int n)
 {
    int j = 0;
    for(j=2; j<=sqrt(n); j++)     //求素数的结论，只要存在一个(>1的)因数<=这个数(n)的开方，那么这个数(n)就不是素数
    {
        if(n%j==0)
            return 0;   
        else
            return 1;
    }
 }
 int main()
 {
    int i = 0;
    scanf("%d", &i);
    if(is_prime(i) == 1)
        printf("i=%d是素数\n", i);
    else
        printf("i=%d不是素数\n", i);
    return 0;
 }
