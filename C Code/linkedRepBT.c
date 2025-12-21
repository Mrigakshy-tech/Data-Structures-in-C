#include<stdio.h>
#include<malloc.h>
 
struct node{          // self referential structure 

    int data;
    struct node* left;  
    struct node* right;
};

struct node* createNode(int data){
    struct node *n;  // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node));  // allocating memory in the heap
    n->data = data;  // setting the data
    n->left = NULL;  // setting the left and right children to NULL.
    n->right = NULL; // setting the left and right children to NULL.
    return n;        // Finally returning the created node
}

int main(){
   /* 
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));  // new root node created
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

     struct node *p1;
    p = (struct node *)malloc(sizeof(struct node));  // second node created
    p->data = 1;
    p->left = NULL;
    p->right = NULL;

     struct node *p2;
    p = (struct node *)malloc(sizeof(struct node));  //  third node created
    p->data = 4;
    p->left = NULL;
    p->right = NULL;

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    */
    
    // new root node created using function
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);
     
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    return 0;
}