//streambin.cpp
#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;
// 结构clothing
struct clothing 
{
    char label[12];  // 编号
    int numberRemaining;  // 剩余件数
};
/*
  函数getNumber：在文件ifile中查找标签为lable的服装数量
  参数ifile：存放服装信息的文件，label：要查找的服装标签
  返回值：标签为label的服装数量
  说明：文件中ifile中存放着服装信息，服装信息为以二进制写入的一个个clothing结构变量
*/
int getNumber(ifstream &ifile, char *label)
{
    clothing  t;
    // 读出种服装信息到t中
    ifile.read((char*)&t,sizeof(clothing));
    while(!ifile.eof())
    {
        if(strcmp(label, t.label)==0)
        {
            return t.numberRemaining;
  	}
        ifile.read((char*)&t,sizeof(clothing));
    }
    return 0;
}
