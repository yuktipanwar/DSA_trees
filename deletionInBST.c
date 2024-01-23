#include <stdio.h>
#include <stdlib.h> 


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

struct node *inOrderPredecessor(struct node* root){
    //inOrder predecessor is left subtree's right most child
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;        //when leaf node is found
}

struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){  //leaf node
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);      //the root here will keep changing as the function is reccursive
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);   //delete the predecessor node
    }
    return root;
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

    inOrder(p);
    //deleteNode(p,3);
    printf("\n");
    deleteNode(p,5);
    printf("|Data is %d |", p->data);
    printf("\n");
    inOrder(p);
    return 0;
}



