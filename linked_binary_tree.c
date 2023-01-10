#include<stdio.h>
#include<malloc.h>

// creating struct of Node
typedef struct Node{
    int data;
    struct Node *left; // self reference node
    struct Node *right;
}Node;

Node *createNode(int data); // initialisation of funtion.

int main(){
    /*
    //construct the root node
    Node *p = (Node*)malloc(sizeof(Node));
    p->left = NULL;
    p->data =2;
    p->right = NULL;
    //construct the second node
    Node *p1 = (Node*)malloc(sizeof(Node));
    p1->left = NULL;
    p1->data =3;
    p1->right = NULL;
    //construct the third node
    Node *p2 = (Node*)malloc(sizeof(Node));
    p2->left = NULL;
    p3->data =3;
    p2->right = NULL;

    // linking the root nodes with left and right nodes.
    p->left = p1;
    p->right = p2;
    */
   Node *root = createNode(2);
   Node *p1 = createNode(3);
   Node *p2 = createNode(4);
   printf("root value: %d\n", root->data);
    // linking the root nodes with left and right nodes.
    root->left = p1;
    root->right = p2;
    return 0;
}

// funtion for creating Nodes
Node *createNode(int data){
    Node *node; // creating the node pointer
    node = (Node*)malloc(sizeof(Node)); // allocate memory for the node
    node->data = data; // set the data into the node pointer
    node->left = NULL;
    node->right = NULL;
    return node;
}