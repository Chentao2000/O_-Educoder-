// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
		int n;
		int h, l;
		int max, mid, min;
		int i = 0;

		cin >> n;

	while(n != 495)
	{
		int a = n / 100;
		int b = n / 10 % 10;
		int c = n % 10;

	
		if (a <= b)
		{
			if (c >= b)
				{
					mid = b;
					max = c;
					min = a;
				}
			else if (c >= a)
				{
					mid = c;
					max = b;
					min = a;
				}
			else
				{
					mid = a;
					max = b;
					min = c;
				}
		}
		else
		{
			if (c < b)
			{
				mid = b;
				max = a;
				min = b;
			}
			else if(c < a)
			{
				mid = c;
				max = a;
				min = b;
			}

			else if (c > a)
			{
				mid = a;
				max = c;
				min = b;	
			}
		}
		h = max * 100 + mid * 10 + min;
		l = min * 100 + mid * 10 + max;

		i ++;

		n = h - l;

		std::cout << i << ":" << h << "-" << l << "=" << n << std::endl;
	}
	return 0;
}
