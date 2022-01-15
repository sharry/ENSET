// Exercice 3 | Manipulation d'un tableau
// 1. Déclarations globales
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int *data;
} Array;

// 2. Les fonctions
// Création de l'espace dynamique
Array createElements(int n)
{
    Array arr;
    arr.size = n;
    arr.data = (int *)calloc(n, sizeof(int));
    return arr;
}
// Saisir les données du tableau
void scanElements(Array arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", arr.data + i);
    }
}
// Décaler à droite
void shiftRight(Array arr)
{
    int *tmp = (int *)calloc(arr.size, sizeof(int));
    for (int i = 0; i < arr.size; i++)
        *(tmp + i) = i != 0 ? *(arr.data + i - 1) : *(arr.data + arr.size - 1);
    for (int j = 0; j < arr.size; j++)
        *(arr.data + j) = *(tmp + j);
    free(tmp);
}
// Décaler à gauche
void shiftLeft(Array arr)
{
    int *tmp = (int *)calloc(arr.size, sizeof(int));
    for (int i = 0; i < arr.size; i++)
        *(tmp + i) = i < arr.size - 1 ? *(arr.data + i + 1) : *(arr.data);
    for (int j = 0; j < arr.size; j++)
        *(arr.data + j) = *(tmp + j);
    free(tmp);
}
// Afficher les données d'un tableau
void printArray(Array arr)
{
    printf("|");
    for (int i = 0; i < arr.size; i++)
        printf("|\t%d\t|", *(arr.data + i));
    printf("|");
}
// Compter l'occurrence d'un élément
int occurrencesCount(Array arr, int sbj)
{
    int count = 0;
    for (int i = 0; i < arr.size; i++)
        count += *(arr.data + i) == sbj ? 1 : 0;
    return count;
}
// Supprimer la première occurrence
void deleteOccurrence(Array *arr, int sbj)
{
    if (occurrencesCount(*arr, sbj) > 0)
    {
        int pos = -1;
        for (int k = 0; k < arr->size; k++)
        {
            if (*(arr->data + k) == sbj)
            {
                pos = k;
                break;
            }
        }
        int *tmp = (int *)calloc(arr->size - 1, sizeof(int));
        for (int i = 0, x = 0; i < arr->size; i++)
        {
            if (i != pos)
            {
                *(tmp + x) = *(arr->data + i);
                x++;
            }
        }
        arr->data = (int *)realloc(arr->data, (arr->size - 1) * sizeof(int));
        arr->size--;
        for (int j = 0; j < arr->size - 1; j++)
            *(arr->data + j) = *(tmp + j);
        free(tmp);
    }
}
// Supprimer tous les occurrences
void deleteOccurrences(Array *arr, int sbj)
{
    int oc = occurrencesCount(*arr, sbj);
    if (oc > 0)
    {
        int size = arr->size - oc;
        int *tmp = (int *)calloc(size, sizeof(int));
        for (int i = 0, x = 0; i < arr->size; i++)
        {
            if (*(arr->data + i) != sbj)
            {
                *(tmp + x) = *(arr->data + i);
                x++;
            }
        }
        arr->data = (int *)realloc(arr->data, size * sizeof(int));
        arr->size = size;
        for (int j = 0; j < arr->size; j++)
            *(arr->data + j) = *(tmp + j);
        free(tmp);
    }
}

// 3. Program principal
int main(int argc, char const *argv[])
{
    // a)
    Array table;
    // b)
    printf("Definissez la taille du tableau: ");
    scanf("%d", &table.size);
    table = createElements(table.size);
    // c)
    scanElements(table);
    // d)
    printf("\nVotre tableau:\n");
    printArray(table);
    // e)
    shiftLeft(table);
    // f)
    printf("\nDecalage a gauche:\n");
    printArray(table);
    // g)
    shiftRight(table);
    // h)
    printf("\nDecalage a droite:\n");
    printArray(table);
    // i)
    int del;
    printf("\nEntrez la valeur a supprimer: ");
    scanf("%d", &del);
    deleteOccurrences(&table, del);
    // j)
    printf("\nVotre table:\n");
    printArray(table);
    return 0;
}
