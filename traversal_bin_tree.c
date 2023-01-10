#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

// function to creata a new node
Node* AddNode(int data){
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function for traversing the tree 
void *preOrder(Node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left); // recusively traverse
        preOrder(root->right); // recusively traverse
    }
}
void *postOrder(Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
void inOrder(Node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main(){
    // initialize the Node of the tree structure
    Node *root = AddNode(1);
    Node *p = AddNode(2); 
    struct Node *p1 = AddNode(3);
    Node *p2 = AddNode(4);
    struct Node *p3 = AddNode(5);
    //                   1 -> root Node/parent Node/level 1
    //                 /   \   
    //  parent node-> 2     3->child Node/leave Node/level 2
    //              /  \ 
    //             4   5->child Node/leave Node/level 3
    
    // linking the Nodes together
    root->left = p;
    root->right = p1;
    p->left = p2;
    p->right = p3;

    // traversing the tree
    printf("This is preorder traversal: \n");
    preOrder(root);
    printf("\nThis is postorder traversal: \n");
    postOrder(root);
    printf("\nThis is inorder traversal: \n");
    inOrder(root);
    return 0;
}