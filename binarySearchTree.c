#include <stdio.h>
#include <stdlib.h> //to create root node

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// function that returns node pointer.
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// reccursive function
void inOrder(struct node *root)
{
    if (root != NULL)
    { // termination condition of recurssive function.
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Checking if the given tree is BST?
int isBST(struct node *root)
{

    // using static because we don't want each stack to have it's own prev pointers.
    static struct node *prev = NULL; // previous is a pointer to check for children. As the root node isn't a children of anyone so we initialize prev as NULL.
    if (root != NULL)
    { // termination condition of recurssive function.
        if (!isBST(root->left))
        {
            return 0; // if left subtree is not BST then return false.
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);    //check for right subtree
    }
    else
    {
        return 1;
    }
}

int main()
{

    // Constructing the nodes using function (recommended)
    struct node *p = createNode(5);

    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // Finally the binary search tree looks like:
    /*
                5
               / \
              3   6
             / \
            1   4
    */

    // linking the root node with left and right children.
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("InOder Traversal BST gives ascending sorted array-\n");
    printf("Is it a BST?: %d", isBST(p));
    printf("\n");
    inOrder(p);
    return 0;
}
