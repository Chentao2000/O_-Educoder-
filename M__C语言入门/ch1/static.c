#include <stdio.h>
void test()
{
    //int a = 1; //若不用static，那么每次函数进入循环出来后，a都会变回为1，输出：2 2 2 2 2 
    static int a = 1; //使a变为静态的局部变量，也就是保存上一次得到的a， 输出：2 3 4 5 6
    a++;
    printf("%d\n", a);
}
int main()
{
    int i = 0;
    while(i<5)
    {
        test();
        i++;
    }
    return 0;
}
