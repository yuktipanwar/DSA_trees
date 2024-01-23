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

void insertBST(struct node *root, int key){
    struct node *prev= NULL;
    while(root!=NULL){
        prev = root;
        if(key==root->data){
            printf("Cannot insert %d as it is already in BST.",key );
            return;             //we won'e insert as in BST no duplicates are allowed.
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node* new = createNode(key);
    if(key<prev->data){
        prev->left=new;
    }else{
        prev->right=new;
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


    insertBST(p,7);
    printf("%d\n", p->right->right->data);
    insertBST(p,6);
    return 0;
}



