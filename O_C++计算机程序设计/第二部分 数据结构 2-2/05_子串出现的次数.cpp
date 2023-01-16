// 包含字符串函数库
#include <string.h>
#include <iostream>
using namespace std;

int frequency(char * substr, char * str);

int main()
{
    char sub[128],str[1024];
    cin.getline(sub,128);     // 输入子串
    cin.getline(str,1024);     // 输入长串
    int n = frequency(sub,str);     // 调用frequency函数，计算子串在长串中出现的次数
    cout<<n<<endl;     // 输出次数
    return 0;
}

// 函数frequency：计算子串在长串中出现的次数
// 参数：substr-指向子串，str-指向长串
// 返回值：出现的次数
int frequency(char * substr, char * str)
{
    // 请在此添加代码，实现函数frequency
    /********** Begin *********/
   int ans = 0;

    while(*str!= '\0'){
   if (strstr(str,substr) != NULL){
    ans++;
       while(str!=strstr(str,substr))
        str ++ ;    
    // 这样一直跳过下一个子串相同的字符相同的地方 ，注意此时返回的是首地址 ，是接下来一连串的全部 字符 ，教材解释的很清楚了 （而非当个字符）
   }
   for(int i =0 ; i<strlen(substr);i++)
    str++;// 跳过子串 查看后面的串
    }
    return ans;
    
    /********** End **********/
}



