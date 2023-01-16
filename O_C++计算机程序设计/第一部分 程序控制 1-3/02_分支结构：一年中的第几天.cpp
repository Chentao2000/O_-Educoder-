// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    // y-年，m-月,d-日，n-第几天
    int y, m, d, n;
    // 请在此添加代码，计算并输出指定日期是第几天
    /********** Begin *********/
    cin >> y >> m >> d ;
    bool year_29_flag = 0 ;  // 0 代表不是闰年 1 代表是 闰年
    // -----------------------------------------------------------------
    // 首先判断年
    	if ( (y%4==0)&& (y%100!= 0) )  {
        year_29_flag = 1  ;
    }
    else if (y %400 == 0){
       year_29_flag = 1  ;
    }
    else{
         year_29_flag = 0;
    }
    // 接下来根据月算天数 
    // 一月 31天  二月 28/29 天 三月 31天 四月30天 五月31天  六月30天
    // 七月 31天 八月 31天 九月 30天 十月 31天 十一月 30天 十二月 31天 
 // -----------------------------------------------------------------
    switch(m){
        case 1 : 
            n = d;
        break;

        case 2 : 
            n = 31 + d;
        break;

        case 3 : 
                  if (year_29_flag)
                n =  31 + 29 + d;
            else
                n = 31 + 28  + d;
        break;

        case 4 : 
                 if (year_29_flag)
                n =  31 + 29 + 31 + d;
            else
                n = 31 + 28 + 31 + d;
        break;

        case 5 : 
                  if (year_29_flag)
                n =  31 + 29 + 31 +30 + d;
            else
                n = 31 + 28 +31 +  30 + d;
        break;

        case 6 : 
                    if (year_29_flag)
                n =  31 + 29 + 31 +30 +31+ d;
            else
                n = 31 + 28 +31 +  30+31 + d;
        break;

        case 7 : 
                    if (year_29_flag)
                n =  31 + 29 + 31 +30 +31+30+ d;
            else
                n = 31 + 28 +31 +  30+31 +30+ d;
        break;

        case 8 : 
                    if (year_29_flag)
                n =  31 + 29 + 31 +30 +31+30+31+ d;
            else
                n = 31 + 28 +31 +  30+31 +30+31+ d;
        break;

        case 9 : 
                    if (year_29_flag)
                n =  31 + 29 + 31 +30 +31+30+31+31+ d;
            else
                n = 31 + 28 +31 +  30+31 +30+31+31+ d;
        break;

        case 10 : 
                    if (year_29_flag)
                n =  31 + 29 + 31 +30 +31+30+31+31+30+ d;
            else
                n = 31 + 28 +31 +  30+31 +30+31+31+30+ d;
        break;

        case 11 : 
                    if (year_29_flag)
                n =  31 + 29 + 31 +30 +31+30+31+31+30+31+ d;
            else
                n = 31 + 28 +31 +  30+31 +30+31+31+30+31+ d;
        break;

        case 12 : 
                    if (year_29_flag)
                n =  31 + 29 + 31 +30 +31+30+31+31+30+31+30+ d;
            else
                n = 31 + 28 +31 +  30+31 +30+31+31+30+31+30+ d;
        break;

    }
    
    
    /********** End **********/
    printf("%d-%d-%d是第%d天\n",y,m,d,n);
    return 0;
}
