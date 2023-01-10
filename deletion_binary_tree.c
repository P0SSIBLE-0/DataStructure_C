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

Node *inOrderPredecessor(Node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}
// function for deletion the node 
Node * deleteNode(Node* root,int value){
    
    Node* inPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
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
        inPre = inOrderPredecessor(root);
        root->data = inPre->data;
        root->left = deleteNode(root->left, inPre->data);
    }
    return root;
}

int main(){
    Node *root = createNode(5);
    Node *p = createNode(2);
    Node *p1 = createNode(9);
    Node *p2 = createNode(4);
    Node *p4 = createNode(1);

    root->left = p;
    root->right = p1;
    p->right = p2;
    p->left = p4;
    inOrder(root);
    printf("\n");
    // deleteNode(root,5);// deleting the root node
    //deleteNode(root,4); // deleting the null node
    deleteNode(root,2); // deleting the non-null node
    inOrder(root);
    return 0;
}