// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n;

    // 请在此添加代码，输入正整数n，如果n是素数则输出“Yes”，否则输出“No”
    /********** Begin *********/
    // 把素数一分为二 然后遍历 。
    cin >> n ;
    int temp = 0;
    temp = n/2 ;

    for(int i =2 ;i< temp ;i++){
    
        if ( n%i ==0 ){
            cout << "No";
            return 1 ;
        }
        
    }
         cout << "Yes";


    /********** End **********/

    return 0;
}
