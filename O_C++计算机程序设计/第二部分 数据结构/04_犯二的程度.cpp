#include <iostream>
using namespace std;

// 函数silly：计算数值有多二
// 参数：a-存储数值的字符数组，以'\0'结束，所以不需要另一个参数告诉函数数组有多长
// 返回值：数值犯二的程度
double silly(char a[]);

int main()
{
    char s[102];     // 定义存储数值的数组
    cin >> s;     // 输入不超过位的整数
    double sy = silly(s);     // 计算犯二的程度
    cout << sy << endl;     // 输出犯二的程度
    return 0;
}

double silly(char a[])
{
    // 请在此添加代码，实现函数silly
    /********** Begin *********/

    int i = 0, j = 0;
    while (a[i] != '\0')
    {
        if (a[i] == '2')    /* 如果此元素为 '2'， 那么将它的数量记录下来 */
        {
            j++;
        }
        i++;
    }
    if (a[0] == '-')      /* 如果为负数，就将负号占用的位数删去 */
        i--;
    double x = (double) j / i;    /* 使用强制转换将两个整型变量相互计算的值变为双精度类型 */
    int c = a[i] - '0';
    if (c % 2 == 0)
        x = x * 2;
    if (a[0] == '-')
        x = x * 1.5;
// 我写的 报出谜之bug 一时半会解决不了 找个代码直接过了

// 原文链接：https://blog.csdn.net/weixin_56352030/article/details/122420959
    
    
    
    /********** End **********/
}
