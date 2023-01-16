#include <iostream>
using namespace std;

// 递归函数splitNum：顺序输出n的各位数字，每个数字占一行
// 返回值：无
void splitNum(unsigned int n)
{
    int m = 0 ;
    // 请在这里补充代码，实现递归函数splitNum
    /********** Begin *********/
	// 递归的好处是 存储中间值 ，但是 是 以损失空间为代价的
    if(n <10){
     cout << n << endl;
    } // 如果是小数直接输出得了 因为我们递归最起码是两位数
    else {
        m = n%10;//最低位
        n = n/10;//移去最低位剩下的部分
        if (n >10){
              splitNum(n); // 先递归 再输出 递归回来一定是最高位
        }
        else
            cout << n << endl;
        
        cout << m << endl;

    
    }

    
    
    /********** End **********/
}

int main()
{
    unsigned n;
    cin >> n;     // 输入正整数n
    splitNum(n);     // 调用splitNum函数，顺序输出n的各位数字
    return 0;
}
