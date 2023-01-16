//sizeof用来计算内存大小，单位是字节
#include <stdio.h>
int main()
{
   int a = 10;
   int arr[10] = {0};//含有十个整型元素的数组
   printf("%d\n", sizeof(a));//整型是4个字节，所以a和int都为4个字节
   printf("%d\n", sizeof(int));
   printf("%d\n", sizeof(arr));//arr里有十个元素，所以是4x10=40个字节
   return 0;
}
