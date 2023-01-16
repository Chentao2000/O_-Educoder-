#include <stdio.h>
int main()
{
    int day = 0;
    scanf("%d", &day);    //记得scanf要用&取地址
    switch(day)
    {
        case 1:
            printf("星期一\n");
            break;        //case完要用break，否则会从你输入的数字一直打印到最后
        case 2:
            printf("星期二\n");
            break;
        case 3:
            printf("星期三\n");
            break;              
        case 4:
            printf("星期四\n");
            break;
        case 5:
            printf("星期五\n");
            break;
        case 6:
            printf("星期六\n");
            break;
        case 7:
            printf("星期日\n");
            break;
    }
    return 0;
}
