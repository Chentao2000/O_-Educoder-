#include <stdio.h>
int main()
{
    int age = 10;
    if(age < 18)
        printf("未成年");
    else    //在else里面写代码块
    {
        if(age >= 18 && age <= 28)
            printf("青年");
        else if(age >= 28 && age <= 50)
            printf("壮年");
        else if(age >= 50 && age < 90)
            printf("老年");
        else                    
            printf("老不死");   
    }
    
    return 0;
}
