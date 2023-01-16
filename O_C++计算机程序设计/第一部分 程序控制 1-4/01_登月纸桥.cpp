#include <iostream>
using namespace std;

// foldTimes-计算建纸桥的折叠次数
// 参数：dis-星际距离（千米），thick-纸的厚度（毫米）
// 返回值：建桥需要折叠的次数
int foldTimes(double dis, double thick);

int main()
{
    double dis, thick;
    cin >> dis >> thick;
    cout << "需要折叠" << foldTimes(dis,thick) << "次" << endl;
    return 0;
}

int foldTimes(double dis, double thick)
{
    // 请在这里补充代码，实现函数foldTimes
    /********** Begin *********/
    //折一次  厚度翻倍
    // 还要注意单位换算 1km = 1*10^3 m = 1*10^6mm
    int num = 0;
    while(thick < dis*1000000){
        thick = thick * 2;
        num++;
        // 注释是调试用的
       // cout <<"num  "<< num<<endl;
       // cout <<"thick  "<< thick<<endl;

    }
    return num;
    
    
    /********** End **********/
}
