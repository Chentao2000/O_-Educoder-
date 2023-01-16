/*************************************************************
    date: February 2019
**************************************************************/

//求子串 实现文件
/////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SubStr.h"

void SubStr(SString t, SString s,int i,int len)
//从s的第i个字符开始截取长度为len的子串存入t中。
//其中1≦i≦串s的长度, 0≦len≦ 串s的长度-i+1。
//若i和len超出取值范围，则输出"error"；否则输出子串t。
{
	// 请在这里补充代码，完成本关任务
    /********** Begin *********/
   int h = 0,j=0;
   char p = 'a';
   while(s[h] !='\0'){
       h ++ ;
      // printf("%d",h);
   }
   if( h < (i+len) ){
       printf("error");
   }else{
      while(len !=0)
    {
        
       printf("%c",s[i++]);
       len --;
    }       
       
   }
          
	
    /********** End **********/
}

