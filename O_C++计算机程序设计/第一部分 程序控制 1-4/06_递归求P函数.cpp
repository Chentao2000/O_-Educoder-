#include <iostream>
using namespace std;

// 函数funP：实现数学函数P函数
// 返回值：返回P(n,x)的值
double funP(int n, double x)
{
    
    // 请在这里补充代码，实现递归函数funP
    /********** Begin *********/
    // 照着数学式敲就好了
    // 斐波那契数列（Fibonacci sequence），又称黄金分割数列
    // 斐波那契数列 ：F(0)=0，F(1)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 2，n ∈ N*）
    // 他给的函数  : F(0)=1，F(1)=x, F(n)= ((2n-1) F(n - 1)... + (n-1)F(n - 2))/n....（n ≥ 2，n ∈ N*）

    if(n == 0 ){
        return 1 ;
    }
    else if(n == 1){
        return x;
    }
    else if(n > 1){
    
        return  ((2*n-1)*funP(n-1,x) - (n-1)*funP(n-2,x))/n;
    }
    
    
    
    /********** End **********/
}

int main()
{
    int n;
    double x;
    cin >> n >> x;     // 输入n、x
    cout << "P("<<n<<", "<<x<<")=" << funP(n,x) << endl;
    return 0;
}
