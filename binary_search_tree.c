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

// function to check whether a tree is Binary search tree or not!
int isBST(Node* root){
    static Node *prev = NULL; //  static used for avoiding different value in recursive functions.
    if(root!=NULL){
        if(!isBST(root->left)){ // recursive function call for root left node
            return 0;
        }
        if(prev!=NULL && prev->data >= root->data){ // if prevdata is greater than rootdata
            return 0;                               // then is not a binary search tree. so return 0
        }
        prev = root; 
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

// fuction for checking whather the element is in the tree or not.
Node* search(Node *root,int key){
    if (root==NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    else if (root->data > key){
       return search(root->left,key);
    }
    else{
       return search(root->right,key);
    }
    
}
// function for finding element in binary search tree using itrative method
Node* searchIter(Node *root, int key){
    while (root!=NULL)
    {
        if(key == root->data){
            return root;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
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
    if (isBST(root))
    {
         printf("this is binary tree\n");
    }
    else{
        printf("Nope! this is not a binary tree\n");
    }
    
    int element = 5;
    // Node *n = search(root, element);
    Node *n = searchIter(root, element);
    if (n != NULL){
        printf("%d is founded \n", n->data);
    }
    else{
        printf("%d is Not found\n", element);
    }
    return 0;
}