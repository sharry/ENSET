#include <stdio.h>
int f1(int *p, int **pp)
{
    int y, z = ++**pp;
    y = ++*p;
    return ++y + z;
}
int main()
{
    int c = 4, *b = &c, **a = &b;
    printf("%d\n", c + f1(b, a));
    return 0;
}