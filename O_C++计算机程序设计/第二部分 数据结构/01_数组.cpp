#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n, a[30], i;     // 定义变量及数组，n-销售额个数，a-销售额
    cin >> n;     // 输入销售额数量，n <= 30
    // 输入n个销售额，分别存入a[0]到a[n-1]
    for(i = 0; i < n; i++)
        cin >> a[i];
    // 请在此添加代码，计算并输出销售额的波动情况
    /********** Begin *********/
    int my_count = 0;
    for(i =1 ; i < n; i++){
     my_count = a[i] - a[i-1];

     // count - endl 自带回车 所以使用 printf
     // cout << my_count  << endl;   
     printf("%d ",my_count);
    }
	
    
    
    /********** End **********/
    return 0;
}
