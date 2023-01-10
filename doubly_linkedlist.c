#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* Travers_forward(Node* head){
    Node*ptr = head;
    while (ptr!= NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
Node* travers_back(Node* head){
    Node*ptr = head;
    while (ptr!= NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

int main(){
    Node* head;
    Node* second;
    Node* third;
    Node* fourth;
    head = (Node*) malloc(sizeof(Node));
    second = (Node*) malloc(sizeof(Node));
    third = (Node*) malloc(sizeof(Node));
    fourth = (Node*) malloc(sizeof(Node));

    // linking the list:-
    head->prev = NULL;
    head->data = 10;
    head->next = second;

    second->prev = head;
    second->data = 11;
    second->next = third;

    third->prev = second;
    third->data = 12;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 13;
    fourth->next = NULL;
    printf("traversal forward:-\n");
    Travers_forward(head);
    printf("traversal Backward:-\n");
    travers_back(fourth);
    return 0;
}