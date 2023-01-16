#include <iostream>
using namespace std;

struct rationalNumber{
    int fenzi; // 分子
    int fenmu; // 分母
};

// 函数rnMean：计算n个有理数的平均数
// 参数：a-存放有理数的数组,n-有理数的个数
// 返回值：n个有理数的平均数
rationalNumber rnMean(rationalNumber a[], int n);

int main()
{
    char c;
    rationalNumber a[100],z;
    int n, i;
    cin >> n;     // 输入有理数个数
    // 输入n个有理数
    for(i = 0; i < n; i++)
        cin >> a[i].fenzi >> c >> a[i].fenmu;
    z = rnMean(a,n);     // 计算有理数平均数
    // 输出平均数
    if(z.fenmu == 1)
        cout << z.fenzi << endl;
    else
        cout << z.fenzi << "/" << z.fenmu << endl;
    return 0;
}

// 请在此添加代码，实现函数rnMean
/********** Begin *********/

rationalNumber reduction(rationalNumber n)  
{  
    int flag = 1,k;  
    if(n.fenzi < 0)  
    {  
        n.fenzi = -n.fenzi;  
        flag = -1;  
    }  
    k = (n.fenmu > n.fenzi) ? n.fenzi : n.fenmu;  
    while(k > 1)  
    {  
        if(n.fenmu%k == 0 && n.fenzi%k == 0)  
        {  
            n.fenmu = n.fenmu / k;  
            n.fenzi = n.fenzi / k;  
        }  
        k--;  
    }  
    n.fenzi = n.fenzi * flag;  
    return n;  
}

rationalNumber rnAdd(rationalNumber x, rationalNumber y)  
{ 
    rationalNumber z;
    x.fenzi = x.fenzi* y.fenmu;
    y.fenzi = y.fenzi* x.fenmu;
    z.fenzi = x.fenzi + y.fenzi;
    z.fenmu = x.fenmu*y.fenmu;
 
 return reduction(z);//
}

rationalNumber rnMean(rationalNumber a[], int n)
{
    rationalNumber x = {0,1};  
    int i;  
    for(i = 0; i < n; i++)  
    {  
        x = rnAdd(x,a[i]);  
    }  
    x.fenmu = x.fenmu * n;  
    x = reduction(x);  
    return x;  
}
/********** End **********/
