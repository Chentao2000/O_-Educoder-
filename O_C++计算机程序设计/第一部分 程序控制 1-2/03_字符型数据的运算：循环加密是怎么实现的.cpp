// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    // c-存储输入的大写字母,d-存储加密后的大写字母
    char c, d;
    // step-秘钥，往前走的步数，大于等于 1，小于 26
    int step;
    // 请在Begin-End之间添加代码，计算密文存入 d 中
    /********** Begin *********/

	cin >> c >> step;

    d = (c+step >= 'A' && c+step <= 'Z' ? c+step : 'A' + c + step - 'Z' - 1);
  
    /********** End **********/
    // 输出密文
    cout << d;
    return 0;
}
