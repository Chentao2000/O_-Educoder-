#include <stdio.h>
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int k = 7;
    int sz = sizeof(arr)/sizeof(arr[0]);
    int left = 0;            //左下标
    int right = sz-1;        //右下标
    int mid = (left+right)/2 //中间下标
    if(arr[mid] > k) 
    {
        right = mid - 1;     //比mid小，故范围变为mid的左边，right ~ mid-1
    }
    else if(arr[mid] < k)
    {
        left = mid+1;
    }
    else
    {
        printf("找到了，下标是%d\n", mid);
    }
    return 0;
}
