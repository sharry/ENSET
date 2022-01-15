#include <stdio.h>
int main()
{
    int i = 5, m = i % 3;
    float r = i / 10;
    printf("(%d, %.2f)\n", m, r);
    return 0;
}