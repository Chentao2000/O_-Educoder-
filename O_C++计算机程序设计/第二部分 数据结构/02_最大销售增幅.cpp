#include <iostream>
using namespace std;

// 函数maxIncrease：计算销售额增幅
// 参数：s-销售额数组，n-销售额数组长度，n>1
// 返回值：销售额最大增幅
int maxIncrease(int s[], int n);

int main()
{
    int n, a[30], i;     // 定义变量及数组，n-销售额个数，a-销售额数组
    cin >> n;      // 输入销售额数量，n>1
    // 输入n个销售额，分别存入a[0]到a[n-1]
    for(i = 0; i < n; i++)
        cin >> a[i];
    i = maxIncrease(a,n);
    cout << "最大销售增幅为：" << i << endl;
    return 0;
}

int maxIncrease(int s[], int n)
{
    //请在此添加代码，实现函数maxIncrease
    /********** Begin *********/
    // 就算最大销售额 不是相邻的 我还以为是相邻的 ...
    // 要增幅 不要减幅 .....
    // 找一个最大 ，再找一个最小 相互减去就ok了
   // 先 把增幅都记录 到一个数组上 Growth_rate
   // 
    int Growth_rate[n], order_count, Current_maximum;
    int j;
	for (int i = 0; i < n; i++)
	{
        j = i + 1;
        Current_maximum = s[j - 1];
        for (; j < n; j++)
        {
            if (Current_maximum < s[j])
            {
               Current_maximum = s[j];
            }
        }
        Growth_rate[i] = Current_maximum - s[i];
        Current_maximum = 0;
	}
 
    order_count = Growth_rate[0];
    for(int k = 0; k < n; k++)
    {
        if (order_count < Growth_rate[k])
        {
            order_count = Growth_rate[k];
        }
    }
	return order_count;
 

    
    /********** End **********/
}
