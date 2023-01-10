#include<stdio.h>
#include<stdlib.h>

// this is program to check weather a binary tree is binary search tree or not!
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(int data){
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right  = NULL;
    return newNode;
}

void inOrder(Node *root){
    if(root!= NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void insert(Node *root,int key){
    Node *prev = NULL; 
    while (root != NULL)
    {
        prev = root;
        if (key==root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }        
    }
    // linking the Nodes with previous node
    Node *newNode = createNode(key);
    if (prev->data < key)
    {
        prev->right = newNode;
    }
    else{
        prev->left = newNode;
    }
    
}


int main(){
    Node *root = createNode(5);
    Node *p = createNode(1);
    Node *p1 = createNode(9);
    Node *p2 = createNode(4);

    root->left = p;
    root->right = p1;
    p->right = p2;
    inOrder(root);
    printf("\n");
    insert(root,8);
    insert(root,4);
    printf("%d\n",root->right->left->data);
    inOrder(root);
    return 0;
}