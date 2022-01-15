#include <stdio.h>

void f2(int a)
{
    printf("%d ", a);
    if (a > 1)
        f2(a - 1);
    printf("%d ", a);
}
int main(int argc, char const *argv[])
{
    f2(3);
    return 0;
}
