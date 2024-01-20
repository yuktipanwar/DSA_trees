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

// traversal
void inOrder(struct node *root)
{
    if (root != NULL)
    { // termination condition of recurssive function.
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node * searchIter(struct node * root, int key){
    while(root!=NULL){
        
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        root= root->left;
    }
    else{
        root= root->right;
    }
    }
    return NULL;
    
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

    //struct node * n= search(p,10);
    struct node * n= searchIter(p,1);
    if(n!=NULL){
        printf("Found: %d\n", n->data);
    }
    else{
        printf("Element not found\n");
    }
    
    return 0;
}
