#include <iostream>
using namespace std;

void extractNum(char * str);

int main()
{
    char s[1024];
    cin.getline(s,1024);     // 输入一行字符
    extractNum(s);     // 调用extractNum函数，选出数字
    cout<<s<<endl;     // 输出选出的数字
    return 0;
}

// 函数extractNum：选出str指向的字符串中的数字，并写回str
// 参数：str-指向字符串
void extractNum(char * str)
{
    // 请在此添加代码，实现函数extractNum
    /********** Begin *********/
    // 是第一个数字之前有 符号，如果不是第一个数字 ，那就照删不误
     char *p = str;
     
     // 求出负号
     while(*p != '\0'){
         if(*p >= '0' && *p<='9'){
             break ;// 找出第一个数字
         }
       p++;  // 找不到数字就一直移地址 ，找到了就刹住车 不找了， 此时指针的地址指向 的是数字前第一个字符
     } 
// a b c -1 2 3 4 5 6
// ' ' a  b c -1 2 3 4 5 6

     int flagFu = 0;
     char* temp = str;
        while(temp !=p){
            if(*temp == '-'){
                flagFu = 1;
                break;
            }
            temp ++;
        }
    if(flagFu){
        *str = '-';
        str++;
    }

    //求出数字
    p = str;
	while(*p != '\0'){
		if(*p >='0' && *p <='9'){
			*str = * p;
			str++;
		}
		p++;
	}
	*str = '\0'; 
    
    
    
    /********** End **********/
}
