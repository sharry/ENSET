#include <stdio.h>
#include <stdlib.h>

// 1) Déclaration du type TTableauDyn
typedef struct
{
    int *data;
    int size;
} Array;

// 2) Déclaration du type TNoeud
typedef struct t_node
{
    int value;
    struct t_node *next;
} Node;

// 3) Fonction allouerTableau
Array allocateArray(int size)
{
    Array arr;
    arr.size = size;
    arr.data = (int *)calloc(size, sizeof(int));
    return arr;
}

// 4) Fonction saisirTableau
void fillArray(Array arr)
{
    for (int *p = arr.data; p < arr.data + arr.size; p++)
    {
        printf("Saisir valeur Tab[%d]: ", p - arr.data);
        scanf("%d", p);
    }
}

// 5) Fonction tableau2Liste
Node *createNode(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    return node;
}
Node *array2List(Array arr)
{
    Node *temp, *current;
    Node *head = createNode(arr.data[0]);
    current = head;
    for (int i = 1; i < arr.size; i++)
    {
        temp = createNode(arr.data[i]);
        current->next = temp;
        current = temp;
    }
    return head;
}

// 6) Fonction liste2Tableau
Array list2Array(Node **head)
{
    Array arr;
    arr.size = 0;
    Node *temp = *head;
    while (temp)
    {
        arr.size++;
        arr.data = (int *)realloc(arr.data, sizeof(int) * arr.size);
        *(arr.data + arr.size - 1) = temp->value;
        temp = temp->next;
    }
    return arr;
}

// 7) Program principal
int main(int argc, char const *argv[])
{
    // a.
    int size;
    printf("Definissez la taille du tableau: ");
    scanf("%d", &size);
    Array tab = allocateArray(size);
    // b.
    fillArray(tab);
    // c.
    Node *list = array2List(tab);
    //  d.
    printf("Votre tableau: ");
    for (int *p = tab.data; p < tab.data + tab.size; p++)
    {
        printf("[%d]", *p);
    }
    return 0;
}
