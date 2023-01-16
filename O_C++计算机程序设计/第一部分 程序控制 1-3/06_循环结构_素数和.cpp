// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    // 请在此添加代码，输入n和k，并输出n以内k个素数以及它们的和
    /********** Begin *********/
// 借鉴一下别人写的代码 ，自己写的 太混乱了 ，不过也能过
// 原文链接：https://blog.csdn.net/m0_51150485/article/details/117030990
// 不过别人写的 完全不考虑算法 ，只是逻辑清晰点 ，借鉴有限 
    // n-输入的数，m-重排后的数
	int n,k;  // n为素数范围，k为查找的素数个数 
	int sum=0,count=0;  //sum为和，count用于记录查找到的个数 
	scanf("%d%d",&n,&k);
	for(int i=n;i>=2;i--){  //第一重循环为查找素数的值，从n值开始 
		for(int j=2;j<i;j++){  //第二重循环为判断是否为素数 
			if(i%j==0){
				break;
			}
			else{
				while(j==i-1){  //利用while确定素数 
					count++;    //对素数进行计数 
					if(count<=k){  //判断素数个数 
						printf("%d ",i);
						sum=sum+i;
						break;
					}
					
					else{
						break;
					}
				}
			}
		}
		while(count<=k&&i==2){  //特殊情况，当输入的值较小，k值较大时，需要使用值为2的素数 
			printf("%d ",i);
			sum=sum+i;
			break;
		}
		
		
	}
	printf("%d",sum);
    return 0;



    return 0;
}
