
### 示例代码与学习笔记
-----
##### 第一关 ：

##### 第二关 :

例如：下面的程序将一个整型数组中存放的10名同学的百分制成绩转换为5分制，并输出。
```cpp
#include <iostream>  
using namespace std;
// 分数转换函数的函数原型，其中：s-学生成绩数组名，len-学生成绩个数  
void convertScores(int s[], int len);
int main()  
{  
    // 定义学生成绩数组并初始化  
    int scores[10] = {85, 63, 72, 52, 95, 82, 77, 69, 88, 73};  
    convertScores(scores, 10);     // 调用分数转换函数convertScores  
    // 转换完成后输出分数数组中的分数  
    for(int i = 0; i < 10; i++)  
        cout << "scores["<<i<<"] = " << scores[i] << endl;  
    return 0;  
}
// 函数convertScores  
void convertScores(int s[], int len)  
{  
    // 逐个访问数组中的每个元素，并做转换  
    for (int i = 0; i < len; i++)  
        s[i] = s[i]/20;     // 修改 s[i] 实际上就是修改 main 函数中的 scores[i]，因为 s 和 scores 拥有相同的地址值  
}  

```
##### 第三关 :
无

##### 第四关 :
我们可以看到对于字符串而言，它的存储总是以 '\0' 结尾。
例如下面的程序可以计算并输出字符串的长度：
```cpp
char s[1000];     // 定义一维字符数组  
cin >> s;     // 输入一个字符串存入字符数组s中  
int i = 0;
// 逐个判断字符数组的某一位是否是'\0'，该字符意味着字符串的结束  
while(s[i] != '\0')  
    i++;
cout << i << endl;     // 输出字符串的长度  
```
获取字符对应的整数
```cpp
char c = '2';     // c 中存储的是字符 '2' 的ASCII码  
int k = c - '0';     // k 即为字符 '2' 对应的整数 2
```


##### 第五关 :

多维数组在内存中“按行”存放，越靠后的下标先变化，越靠前面的下标后变化。二维数组 a 在内存中的物理存储形式如下图所示：
![image](https://user-images.githubusercontent.com/68007558/178180588-c3d6b9b4-0d3c-49c3-940c-90be7038ce7d.png)

- 例如：下面的程序可以遍历二维数组并输出每一个元素的值。
```cpp
// 定义并初始化二维数组m  
int m[4][4] = { {1, 1, 1, 1},  
                {2, 2, 2, 2},  
                {3, 3, 3, 3},  
                {4, 4, 4, 4}};
// line遍历第一维  
for (int line = 0; line < 4; line++)  
{  
    // col遍历第二维，输出某一行  
    for (int col = 0; col < 4; col++)  
        cout << "\t" << a[line][col];
    // 输出完一行后换行  
    cout << endl;  
}  
```

##### 第六关 
无
