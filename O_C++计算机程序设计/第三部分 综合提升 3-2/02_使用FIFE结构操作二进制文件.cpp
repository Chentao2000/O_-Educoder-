#include <stdio.h>

// 结构clothing
struct clothing {
    char label[12];  // 编号
    float price;  // 价格
};

/* 
   函数readClothing：从文件fp中读取服装信息到cloth中
   参数fp：指向打开的二进制文件，cloth：存放读出的服装信息
   返回值：服装信息数量
   说明：文件中首先以二进制方式存入了一个整数（服装信息数n），然后以二进制方式存入n种服装信息（clothing类型）
*/
int readClothing(FILE *fp, clothing cloth[])
{
    // 请在此添加代码，补全函数readClothing
    /********** Begin *********/
    int n ;
    // 读取一个整数(服装信息数)
    fread(&n,sizeof(n),1,fp);
    fread(cloth,sizeof(clothing),n,fp);
    return n;


    
    /********** End **********/
}
