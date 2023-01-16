#include <stdio.h>
struct Birthday 
{
    int year;
    int month;
    int day;
};

struct Student
{
    char name[30];
    int number;
    double score;
    struct Birthday birthday; //这里的struct Birthday相当于是birthday的类型
};

int main()
{
    int a = 10;
    printf("%d\n", a);
    struct Birthday b; 
    b.year = 2008;
    b.month = 11;
    b.day = 11;
    printf("%d-%d-%d\n", b.year, b.month, b.day);
    
    struct Student mike = {"Mike", 2, 97.5, (struct Birthday){2008, 11, 11}};
    printf("Name:%s NO:%d score:%f Birthday:%d-%d-%d\n", mike.name, mike.number, mike.score, mike.birthday.year, mike.birthday.month, mike.birthday.day);
    return 0;
}
