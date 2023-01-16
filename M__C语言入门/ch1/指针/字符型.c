//字符型同理
#include <stdio.h>
int main()
{
    char ch = 'a';
    char* cp = &ch;
    printf("%p\n", cp);
    *cp = 'b';
    printf("%c\n", ch);
    return 0;
}
