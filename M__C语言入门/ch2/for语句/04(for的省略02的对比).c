#include <stdio.h>
int main()
{
    int i = 0;
    int j = 0;
    for(i=0;i<10;i++)       
    {
        for(j=0;j<10;j++)    
        {
            printf("hi");  
        }                  
    }
    return 0;
}
//如果不省略的话，内部循环完成后，进入外部循环再进入内部循环时，j自动归0.故会打印100次
