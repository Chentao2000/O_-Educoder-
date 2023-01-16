#include<stdio.h>
#include<string.h>

#include"sqstack.h"    //头文件sqstack.h为顺序栈的定义和基本操作的实现

typedef char SElemType;// 定义栈元素类型为字符型

# define MAXSIZE  80

int main()
{
	/********** Begin **********/ 

    SqStack s;
    char a[MAXSIZE], e;
    int i, len;
    InitStack(s);
    scanf("%s", a);
    len = strlen(a);
    for(i=0; i<len; i++)
        Push(s, a[i]);
    for(i=0; i<len; i++)
    {
        Pop(s, e);
        if(a[i]!=e)
            break;
    }
    if(StackEmpty(s))
        printf("%s\nYES\n", a);
    else
        printf("%s\nNO\n", a);


	/********** End **********/	
	return 0;
}
