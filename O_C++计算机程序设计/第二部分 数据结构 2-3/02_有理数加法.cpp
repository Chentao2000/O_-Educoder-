#include <iostream>
using namespace std;

struct rationalNumber{
    int fenzi; // 分子
    int fenmu; // 分母
};

// 函数rnAdd：两个有理数相加
// 参数：x,y-两个有理数
// 返回值：x+y的最简分数形式
rationalNumber rnAdd(rationalNumber x, rationalNumber y);

int main()
{
    char c;
    rationalNumber x, y, z;
    // 输入两个有理数
    cin >> x.fenzi >> c >> x.fenmu;
    cin >> y.fenzi >> c >> y.fenmu;
    z = rnAdd(x,y);     // 有理数相加
    // 输出相加的结果
    if(z.fenmu == 1)
        cout << z.fenzi << endl;
    else
        cout << z.fenzi << "/" << z.fenmu << endl;
    return 0;
}

// 请在此添加代码，实现函数rnAdd
/********** Begin *********/
rationalNumber rnAdd(rationalNumber x, rationalNumber y)
{


    rationalNumber n;
    // 不管正负数 ，我们都要 先通分 ，即分母是相同
    int k_plus = 0;

         // 分母都是正数的 因为题目把负数都写在了分子上
    if(x.fenmu > y.fenmu)
    {

        if(x.fenmu % y.fenmu==0 )
        {
            n.fenmu = x.fenmu ;
            k_plus = x.fenmu/y.fenmu;
         //   cout << "k_plus : " << k_plus << endl;
            y.fenzi =  y.fenzi * k_plus;
            
          //  cout << " x.fenzi: " << x.fenzi << endl;
          //  cout << "程序到这里了"<<endl; //调试
        }
        else // 这种情况呢 是 x y 互为质数 如 2,3 8,9, 17,26 这种
        {
           // 这个时候就是交叉相乘了 
            y.fenzi =  y.fenzi * x.fenmu;
            x.fenzi =  x.fenzi * y.fenmu;
            n.fenmu = x.fenmu * y.fenmu;
        }
    }else
    {
        if(y.fenmu % x.fenmu==0 )
        {
            n.fenmu = y.fenmu ;
            k_plus = y.fenmu/x.fenmu;
         //   cout << "k_plus : " << k_plus << endl;
            x.fenzi =  x.fenzi * k_plus;
            
          //  cout << " x.fenzi: " << x.fenzi << endl;
          //  cout << "程序到这里了"<<endl; //调试
        }
        else
        {
            y.fenzi =  y.fenzi * x.fenmu;
            x.fenzi =  x.fenzi * y.fenmu;
            n.fenmu = x.fenmu * y.fenmu;
        }
    }
//  -------------------------
        n.fenzi = x.fenzi + y.fenzi;


// ---------------------------
    // 化简 程序 ，照搬上一题的 ------
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


    
}
/********** End **********/

