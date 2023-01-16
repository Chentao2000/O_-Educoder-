#include <stdio.h>
enum Sex
{
    MALE,
    FEMALE, //这里是用逗号
    SECRET
}; //注意这里一定要加分号
   //这里的MALE、FEMALE、SECRET都是枚举常量
int main()
{
    printf("%d\n", MALE); //默认为0
    printf("%d\n", FEMALE); //默认为1
    printf("%d\n", SECRET); //默认为2
     
    enum Sex sex = MALE; //在enum Sex中创建一个小变量sex，且让sex = MALE
    printf("%d\n", sex); //这样就能使sex=0 
    return 0;
}
