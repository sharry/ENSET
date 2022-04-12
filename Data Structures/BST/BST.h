#include <iostream>

class BST
{
private:
    int data;
    BST *left;
    BST *right;

public:
    BST(int);
    void insert(int);
    void remove(int);
    void print_inorder();
};

BST::BST(int d)
{
    data = d;
    left = nullptr;
    right = nullptr;
}
void BST::insert(int d)
{
    if (d < data)
    {
        if (!left)
            left = new BST(d);
        else
            left->insert(d);
    }
    else
    {
        if (!right)
            right = new BST(d);
        else
            right->insert(d);
    }
}
void BST::remove(int d)
{
    if (d == data)
    {
        if (!left && !right)
        {
            delete this;
            return;
        }
        else if (!left)
        {
            BST *temp = right;
            delete this;
            *this = *temp;
            return;
        }
        else if (!right)
        {
            BST *temp = left;
            delete this;
            *this = *temp;
            return;
        }
        else
        {
            BST *temp = right;
            while (temp->left)
                temp = temp->left;
            data = temp->data;
            temp->remove(temp->data);
        }
    }
    else if (d < data)
    {
        if (!left)
            return;
        else
            left->remove(d);
    }
    else
    {
        if (!right)
            return;
        else
            right->remove(d);
    }
}

void BST::print_inorder()
{
    if (left)
        left->print_inorder();
    std::cout << data << " ";
    if (right)
        right->print_inorder();
}