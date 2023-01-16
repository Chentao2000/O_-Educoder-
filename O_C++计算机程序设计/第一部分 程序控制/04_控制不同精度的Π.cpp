#include <iostream>

// 包含流操作算子库
#include <iomanip>
using namespace std;

// 定义常量PI，后面可以直接用PI代替后面的数值
#define PI 3.14159265358979323846

int main()
{
    int n;
    // 请在Begin-End之间添加你的代码，输入n，按不同的精度输出 PI。
    /********** Begin *********/
    cin >> n ;
    int X ;

    X = n + 1;// 因为 3.14.... 3也占一位  ----  ATZ

    if(n < 1){ //输入位为 0 的情况
    cout <<  setprecision(X) << PI << endl;

    cout  << setiosflags(ios::showpoint) << setprecision(X+1) << PI << endl;  

    cout  <<setiosflags(ios::showpoint) <<  setprecision(X+2) << PI << endl;  

    cout  <<setiosflags(ios::showpoint) <<  setprecision(X+3) << PI << endl;  

    cout  <<setiosflags(ios::showpoint) <<  setprecision(X+4) << PI << endl;  
    }
    else{

    cout  << setiosflags(ios::showpoint) << setprecision(X) << PI << endl;

    cout  << setiosflags(ios::showpoint) << setprecision(X+1) << PI << endl;  

    cout  <<setiosflags(ios::showpoint) <<  setprecision(X+2) << PI << endl;  

    cout  <<setiosflags(ios::showpoint) <<  setprecision(X+3) << PI << endl;  

    cout  <<setiosflags(ios::showpoint) <<  setprecision(X+4) << PI << endl;  
    }


    
    
    /********** End **********/
    return 0;
}
