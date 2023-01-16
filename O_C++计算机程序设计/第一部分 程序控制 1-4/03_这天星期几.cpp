#include <iostream>
using namespace std;

// 函数leapYear
int leapYear(int y)
{
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    return 0;
}

// 函数whatDay：计算某年某月某日是星期几
// 参数：year-年，month-月
// 返回值：--7分别表示星期一到星期日
int whatDay(int year, int month)
{
    // 原文链接：https://blog.csdn.net/weixin_56352030/article/details/117013982
    // 简单且繁琐 ，直接借鉴网友的了 
	int n = 0, w = 0, i;
	for (i = 1; i < year; i++)
	{
		if(leapYear(i))
		{
			n += 366;

		}
		else
			n += 365;
	}
	
	if(leapYear(year))
		switch(month)
		{
			case 12:
				n += 336;
				break;
			case 11:
				n += 306;
				break;
			case 10:
				n += 275;
				break;
			case 9:
				n += 245;
				break;
			case 8:
				n += 214;
				break;
			case 7:
				n += 183;
				break;
			case 6:
				n += 153;
				break;
			case 5:
				n += 122;
				break;
			case 4:
				n += 92;
				break;
			case 3:
				n += 61;
				break;
			case 2:
				n += 31;
				break;
			case 1:
				n += 1;
				break;
		}
	else 
		switch(month)
		{
			case 12:
				n += 335;
				break;
			case 11:
				n += 305;
				break;
			case 10:
				n += 274;
				break;
			case 9:
				n += 244;
				break;
			case 8:
				n += 213;
				break;
			case 7:
				n += 182;
				break;
			case 6:
				n += 152;
				break;
			case 5:
				n += 121;
				break;
			case 4:
				n += 91;
				break;
			case 3:
				n += 60;
				break;
			case 2:
				n += 32;
				break;
			case 1:
				n += 1;
				break;;
		}	
	w += n;
	w = w % 7;
	if (w == 0) w = 7;

	return w;
}



int main()
{
    int y, m, xq;     // 年、月、星期几
    cin >> y >> m;     // 输入年月
    xq = whatDay(y,m);     // 计算星期几
    cout << y << "年" << m << "月1日是星期";     // 输出星期
    if(xq == 7)
        cout << "日" << endl;
    else
        cout << xq << endl;
    return 0;
}
