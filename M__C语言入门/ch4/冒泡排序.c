#include <stdio.h>
void bubble_sort(int arr[], int sz)
{
    //趟数
    int i = 0;
    for (i=0; i<sz-1; i++)
    {
        int flag = 1; //默认已经有序
        int j = 0;
        for (j=0; j<sz-1-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp; //因为发生位置变换，故无序
                flag = 0;  //本趟排序的数据换成无序
            }
        }
        if (flag == 1) // 只要有一趟没有发生过交换，说明数组已经有序，终止循环 
        {
            break;
        }
    }
}
int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int i = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);
    //arr是数组，我们对数组arr进行传参时，实际上传递过去的时数组arr首元素的地址 &arr[0],所以在自定义函数中，无法定义sz，因为不知道arr全部的大小
    //故sz在自定义函数外面(主函数)定义
    bubble_sort(arr, sz);
    for (i=0; i<sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
