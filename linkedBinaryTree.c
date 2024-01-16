#include<stdio.h>
#include<stdlib.h>  //to create root node

struct node{
    int data;
    struct node* left;
    struct node* right;
};

//function that returns node pointer.
//made to avoid repetitions
struct node* createNode(int data){
    struct node *n;                                  //creating a node pointer
    n=(struct node *)malloc(sizeof(struct node));    //allocating memory in the heap.
    n->data=data;                                   //setting the data
    n->left=NULL;                                   //setting the left and right children to null
    n->right=NULL;
    return n;                                       //returning the created node
}
int main(){

    /*
    //constructing root node
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));             //taking the size of struct node and reserving memory in heap.
    p->data=2;
    p->left=NULL;
    p->right=NULL;

    //constructing second node
    struct node *p1;
    p1=(struct node *)malloc(sizeof(struct node)); 
    p1->data=1;  
    p1->left=NULL;
    p1->right=NULL;

    //constructing third node
    struct node *p2;
    p2=(struct node *)malloc(sizeof(struct node));   
    p2->data=4;
    p2->left=NULL;
    p2->right=NULL;

    //linking the root node with left and right children.
    p->left=p1;
    p->right=p2;
    */

   //Constructing the nodes using function (recommended)
   //constructing root node
    struct node *p=createNode(2);

    struct node *p1=createNode(1);
    struct node *p2=createNode(2);

    //linking the root node with left and right children.
    p->left=p1;
    p->right=p2;





    return 0;
}
