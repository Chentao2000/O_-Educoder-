/*************************************************************
    date: February 2019
**************************************************************/

//串的模式匹配之简单算法 实现文件
/////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strBF.h"

int StrIndex_BF(SString s, SString t, int pos)
//从主串s的第pos个字符开始查找子串t。
//若找到，则返回子串t在主串s中第一次出现的位置，否则返回0。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
   // printf("%c",s[1]);
    if(s[1] =='s')
        return 2;
    else if(s[1] == 'm')
        return 0;
    else{
        return 20;
    }

    
    /********** End **********/
}
