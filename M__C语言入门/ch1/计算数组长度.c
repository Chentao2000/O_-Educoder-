#include <stdio.h>

int main()
{
    int res = 0;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    res = sizeof(arr)/sizeof(int); //用整个数组的内存大小 ÷ 一个字符的内存大小 = 数组里的字符个数（数组的长度）  
    printf("%d\n", res);
    return 0;
}
