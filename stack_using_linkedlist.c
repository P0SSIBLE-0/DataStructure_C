#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL; // here top is global variable.

int isEmpty(Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
int isFull(Node *top)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}
Node *push(Node *top, int value)
{
    if (isFull(top))
    {
        printf("Stack is Overflow!\n");
    }
    else
    {
        Node *n = (Node *)malloc(sizeof(Node));
        n->data = value;
        n->next = top;
        top = n;
        return top;
    }
}
// pop
int pop(Node *Top)
{
    if (isEmpty(Top))
    {
        printf("Stack is Underflow!\n");
    }
    else
    {
        Node *n = Top;
        top = Top->next;
        int x = n->data;
        free(n);
        return x;
    }
}
// get the top element of the stack
int stackTop(){
    return top->data;
}
// get the bottom element of the stack
int stackBottom(){
    Node* ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
    
}
int peek(int pos)
{
    Node* ptr = top;
    for (int i = 0; i < pos -1 && ptr!= NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return  ptr->data;
    }
    else{
        return -1;
    }
}

// traversal
void traversal(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{

    top = push(top, 12);
    top = push(top, 11);
    top = push(top, 10);
    top = push(top, 22);
    traversal(top);
    int Element = pop(top); // here we have pass the address of top to make the change in main().
    printf("the Popped Element of the list is %d\n", Element);
    traversal(top);
    int position = 2;
    printf("peeked at position 2nd in the stack %d\n", peek(position));
    printf("Top element of the stack %d\n", stackTop());
    printf("Bottom element of the stack %d\n", stackBottom());
    return 0;
}