#include <iostream>  
using namespace std;
struct rationalNumber{  
    int fenzi; // 分子  
    int fenmu; // 分母  
};
// 函数reduction：有理数化简，对传入的有理数n进行化简  
// 参数：n-有理数  
// 返回值：无化简后的有理数  
rationalNumber reduction(rationalNumber n);
int main()  
{  
    char c;  
    rationalNumber x, y;  
    cin >> x.fenzi >> c >> x.fenmu;   // 输入有理数，首先读入分子，然后是/，最后是分母  
    y = reduction(x);   // 有理数化简  
    // 输出化简的结果  
    if(y.fenmu == 1)  
        cout << y.fenzi << endl;  
    else  
        cout << y.fenzi << "/" << y.fenmu << endl;  
    return 0;  
}
rationalNumber reduction(rationalNumber n)  
{  
    // 请在这里补充代码，实现函数reduction  
    /********** Begin *********/  
    int flag = 1,k;  
    if(n.fenzi == 0)  
    {  
        n.fenmu = 1;  
        return n;  
    }  
    if(n.fenzi < 0)  
    {  
        n.fenzi = -n.fenzi;  
        flag = -1;  
    }  
    k = (n.fenmu > n.fenzi) ? n.fenzi : n.fenmu;  
    while(k > 1)  
    {  
        if(n.fenmu % k == 0 && n.fenzi % k == 0)  
        {  
            n.fenmu = n.fenmu / k;  
            n.fenzi = n.fenzi / k;  
        }  
        k--;  
    }  
    n.fenzi = n.fenzi * flag;  
    return n;  
    /********** End **********/  
}
