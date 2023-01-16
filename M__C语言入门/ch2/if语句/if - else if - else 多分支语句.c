#include <stdio.h>
int main()
{
    int age = 10;
    if(age < 18)
        printf("未成年");
    else if(age >= 18 && age <= 28)
        printf("青年");
    else if(age >= 28 && age <= 50)
        printf("壮年");
    else if(age >= 50 && age < 90)
        printf("老年");
    else                    //else可有可无
        printf("老不死");   //if. else if, else只会按顺序并只执行其中一个
    return 0;
}
