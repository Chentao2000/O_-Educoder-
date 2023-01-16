#include <stdio.h>
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int k = 7;
    int i = 0;
    int sz = sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<sz;i++)
    {
        if(arr[i]==k)
           { 
               printf("找到了，下标为%d\n",i);
               break;          //注意要break，不然全部下标都走一遍
           }
    }
    if(i==sz)
    {
        printf("没找到\n");
    }
    return 0;
}
