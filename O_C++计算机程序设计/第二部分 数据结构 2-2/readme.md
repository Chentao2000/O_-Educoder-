# 学习笔记 与 示例代码
## 第一关 
例如：之前 sptr 指向字符‘C’的存储单元，执行语句sptr++;后 sptr 则指向字符‘h’的存储单元。如下语句：

```cpp
while(*sptr != '\0')
    sptr++; 
```

则可以使指针 sptr 指向该字符串后面的 '\0'。如果要输出字符串中的部分内容，也可以通过修改指针实现，
```cpp
char s[10] = "China";
char *sptr = s;
sptr++;
cout << sptr;  
```
上述代码执行语句`sptr++;`后，指针 sptr 指向了字符 'h' 的存储单元，此时`cout << sptr;`输出的是 sptr 指向的字符串，即“hina”。
⑧ 同类型的两个指针可以参与各种关系运算，其结果可以反映两指针所指向的地址之间的位置前后关系。
例如：
```cpp
int a[10];
int *p = a, *q = &a[1];
if(p > q)
    cout << "p>q" << endl;
else
    cout << "p<=q" << endl;  

```

上述代码中指针 p 中存放的是 a 的值，也就是 a[0] 的地址，q 中存放的是 a[1] 的地址，而数组元素是按序连续存储的，所以 q 的值要比 p 的值大，程序输出p<=q

## 第二关

C 和 C++ 函数调用的参数传递方式有两种：传值和传引用。    
传值只是值的传递，被调用函数则无法修改实在参数的值；    
传引用则是实参和形参共享实在参数的存储单元，所以被调用函数可以通过修改形参来修改实参的值。   
```cpp
#include <iostream>  
using namespace std;
// 函数inc：将p指向的整数值加  
// 参数：p-int类型指针，指向要加的整数  
void inc(int * p)  
{  
    (*p)++;     // *p 访问 p 指向的单元，++ 将该单元的数据加  
    // 注意不能是 *p++, 因为 * 和 ++ 优先级相同，且右结合，这种写法修改的是 p 的值，而不是 *p 的值  
}
int main()  
{  
    int a = 10;  
    inc(&a);     // 调用 inc 函数，修改 a 的值（传递的是 a 的地址）  
    cout << a << endl;     // 输出 a 的值  
    return 0;  
}  
```

## 第五关 ：



strstr 函数
在一个长串中查找子串可以使用strstr函数，该函数的函数原型为：
```cpp
char* strstr(const char* s1, const char* s2);           
```
该函数从 s1 所指字符串中第一个字符起，顺序向后查找出与 s2 所指字符串相同的子串，若查找成功则返回该子串首次出现的首地址，否则返回 NULL。

例如：
```cpp
char *a="abcdeabcde";  
char *b="bcd";  
cout<<strstr(a,b)<<endl;  
```

该程序输出结果为“bcdeabcde”，因为strstr(a, b)的返回值为“bcd”在“abcdeabcde”中第一次出现的首地址，所以用 cout 输出时，从该位置的字符开始，逐个输出直到 '\0'，即字符串“bcdeabcde”。

当然，查找子串时，也可以从长串的某个位置开始。
```cpp
char *a="abcdeabcde";  
char *b="bcd";  
cout<<strstr(a+4,b)<<endl; 
```

strlen 函数           
另外，下次从什么地方开始查找子串？应该是上次找到子串的开始位置加上子串的长度。其中，函数strlen可以计算字符串的长度，其函数原型为：
```cpp
int strlen(const char *s);  
```
函数 strlen 只有一个参数 s，它是一个字符指针，代表了一个字符串，函数计算 s 指向字符串的长度并返回。


```cpp
char *a="x";  
char *b="Hello world!";     
cout<<strlen(a)<<endl;  // 输出 1     
cout<<strlen(b)<<endl;  // 输出 12  
``` 

![1657524168213](https://user-images.githubusercontent.com/68007558/178210408-541ab31c-061c-4820-b3de-dea3f7ce189f.png)





# 第六关 : 字符串的部分复制:


