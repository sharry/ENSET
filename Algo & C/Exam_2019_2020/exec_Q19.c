#include <stdio.h>

void f3(int a)
{
    if (a > 0)
        f3(a / 2);
    printf("%d ", a);
}
int main(int argc, char const *argv[])
{
    f3(8);
    return 0;
}
