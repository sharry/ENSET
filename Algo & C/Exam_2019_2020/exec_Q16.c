#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, *p;
    p = (int *)malloc(4 * sizeof(int));
    for (i = 0; i < 4; *(p + i) = i, i++)
        ;
    printf("(%d", *p++);
    printf(", %d", (*p)++);
    printf(", %d", *p);
    printf(", %d", *++p);
    printf(", %d)\n", ++*p);
    return 0;
}