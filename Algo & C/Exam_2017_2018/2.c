#include <stdio.h>
#include <stdlib.h>

int compareFiles(char *directoryA, char *directoryB)
{
    FILE *f1 = fopen(directoryA, "r");
    FILE *f2 = fopen(directoryB, "r");
    char ch1, ch2;
    do
    {
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);
        if (ch1 != ch2)
            return 0;
    } while (ch1 != EOF && ch2 != EOF);
    return 1;
}

int main(int argc, char const *argv[])
{
    if (compareFiles("test1.txt", "test2.txt") == 1)
        printf("Les deux fichiers sont identiques.");
    else
        printf("Les deux fichiers sont differents.");
    return 0;
}
