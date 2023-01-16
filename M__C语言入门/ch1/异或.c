#include <stdio.h>
int main()
{
	int a = 3;
   int b = 5;
   int c = a ^ b;
   printf("%d\n", c);
	return 0;
}
//异或的计算规律：对应的二进制位相同则为0，不同则为1
