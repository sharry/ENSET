#include "2.h"
#include <stdio.h>
#include <stdlib.h>

// Afficher le contenu d’un fichier texte F à l’écran
void printFile(FILE *file)
{
    char character;
    int position = ftell(file);
    rewind(file);
    while ((character = getc(file)) != EOF)
        putchar(character);
    fseek(file, position, SEEK_SET);
}

// Compter la fréquence d’un caractère x dans un fichier F
int charCount(FILE *file, char x)
{
    int position = ftell(file);
    rewind(file);
    int count = 0;
    char character;
    while ((character = getc(file)) != EOF)
    {
        if (character == x)
            count++;
    }
    fseek(file, position, SEEK_SET);
    return count;
}

// Substituer toutes les occurrences d’un caractère x dans un fichier F par un caractère y
void replaceChar(FILE *file, char x, char y)
{
    fpos_t epos, pos;
    int c;
    fgetpos(file, &pos);
    fseek(file, 0L, SEEK_END);
    fgetpos(file, &epos);
    rewind(file);
    while (pos != epos)
    {
        c = fgetc(file);
        if (c == EOF)
            break;
        if (c == x)
        {
            fsetpos(file, &pos);
            fputc(y, file);
            fflush(file);
        }
        pos++;
        fsetpos(file, &pos);
    }
    fseek(file, pos, SEEK_SET);
}

// Concaténer deux fichiers F1 et F2 en un fichier F
void concatenateFiles(FILE *file1, FILE *file2, char *seperator)
{
    int position1 = ftell(file1);
    rewind(file1);
    int position2 = ftell(file2);
    rewind(file2);

    FILE *output = fopen("concatenation.txt", "w");
    int character;
    while ((character = getc(file1)) != EOF)
        putc(character, output);
    fputs(seperator, output);
    while ((character = getc(file2)) != EOF)
        putc(character, output);
    fseek(file1, position1, SEEK_SET);
    fseek(file2, position2, SEEK_SET);
    fclose(output);
}

// Programme principale
int main(int argc, char const *argv[])
{
    FILE *file1, *file2;
    char directory1[400], directory2[400];
    int option = 0;
    printf("Entrer le chemin de votre fichier: ");
    scanf(" %s", &directory1);
    char x, y;
    do
    {
        printf("\nChoisir une option:\n");
        printf("\n1)\tAfficher le contenu du fichier");
        printf("\n2)\tCompter la frequence d\'un caractere");
        printf("\n3)\tRemplacer un caractere par un autre");
        printf("\n4)\tConcatener aver un autre fichier");
        printf("\n5)\tQuitter");
        printf("\n\nVotre choix: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            file1 = fopen(directory1, "r");
            printf("\nLe contenu du fichier \"%s\":\n\n", directory1);
            printFile(file1);
            printf("\n\n");
            fclose(file1);
            break;
        case 2:
            file1 = fopen(directory1, "r");
            printf("\nEntrer le caractere a compter la frequence: ");
            scanf(" %c", &x);
            printf("\n Le fichier \"%s\" contient %d fois le caractere %c.\n", directory1, charCount(file1, x), x);
            fclose(file1);
            break;
        case 3:
            file1 = fopen(directory1, "r+");
            printf("\nEntrer le caractere a remplacer: ");
            scanf(" %c", &x);
            printf("Entrer le nouveau catactere: ");
            scanf(" %c", &y);
            replaceChar(file1, x, y);
            fclose(file1);
            break;
        case 4:
            file1 = fopen(directory1, "r");
            printf("\nEntrer le chemin du deuxieme fichier: ");
            scanf(" %s", &directory2);
            file2 = fopen(directory2, "r");
            concatenateFiles(file1, file2, "\n");
            fclose(file1);
            fclose(file2);
            break;
        default:
            break;
        }
    } while (option != 5);

    return 0;
}