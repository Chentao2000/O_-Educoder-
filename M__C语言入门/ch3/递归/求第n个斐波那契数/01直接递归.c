//求第n个斐波那契数
//          n<=2  -> 1
//Fib(n)
//          n>2   -> Fib(n-1)+Fib(n-2)
//设n=50(第50个)
//                   50       （第50个等于第49个+第48个...）               
//             49         48          
//          48    47    47   46      
//        47 46 46 45 46 45 45 44  
//                 .......
//但这种递归就是太特么慢了
 
#include <stdio.h>
int Fib(int n)
{
    if(n<=2)
        return 1;
    if(n>2)
        return Fib(n-1)+Fib(n-2);
}
int main()
{
    int n = 0;
    int res = 0;
    scanf("%d",&n);
    res = Fib(n);
    printf("%d\n", res);
    return 0;
}
