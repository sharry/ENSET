#include "BST.h"

int main(int argc, char const *argv[])
{
    BST *bst = new BST(10);
    bst->insert(5);
    bst->insert(15);
    bst->insert(3);
    bst->insert(7);
    bst->insert(13);
    bst->insert(17);
    bst->insert(1);
    bst->insert(9);
    bst->insert(6);
    bst->print_inorder();
    return 0;
}
