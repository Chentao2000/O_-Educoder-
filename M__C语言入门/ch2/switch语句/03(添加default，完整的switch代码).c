#include <stdio.h>
int main()
{
    int day = 0;
    scanf("%d", &day);
    switch(day)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("工作日\n");
            break;
        case 6:
        case 7:
            printf("休息日\n");
            break;
        default:                   //当输入了case中没有的数字则调用default
            printf("输入错误\n");
            break;
    }
    return 0;
}
