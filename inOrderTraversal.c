#include<stdio.h>
#include<stdlib.h>  //to create root node

struct node{
    int data;
    struct node* left;
    struct node* right;
};

//function that returns node pointer.
struct node* createNode(int data){
    struct node *n;                                  
    n=(struct node *)malloc(sizeof(struct node));    
    n->data=data;                                   
    n->left=NULL;                                   
    n->right=NULL;
    return n;                                       
}

//reccursive function
void inOrder(struct node * root){
    if(root!=NULL){         //termination condition of recurssive function.
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
int main(){

   //Constructing the nodes using function (recommended)
    struct node *p=createNode(4);

    struct node *p1=createNode(1);
    struct node *p2=createNode(6);
    struct node *p3=createNode(5);
    struct node *p4=createNode(2);

    //Finally the tree looks like:
    /*
                4
               / \            
              1   6          
             / \             
            5   2
    */


    //linking the root node with left and right children.
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    inOrder(p);
    return 0;
}
