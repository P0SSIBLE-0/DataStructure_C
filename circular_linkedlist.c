#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;
// Traversal in circular Linked list
Node* traversal(Node* head){
    Node* ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
// insertion in circular linked list At the Beginning
Node* insertAtStart(Node* head, int value){
    Node *ptr = (Node*) malloc(sizeof(Node));
    Node *p = head->next;
    ptr->data = value;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
int main(){
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;
    head = (Node*) malloc(sizeof(Node));
    second = (Node*) malloc(sizeof(Node));
    third = (Node*) malloc(sizeof(Node));
    fourth = (Node*) malloc(sizeof(Node));

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = head;

    traversal(head);
    head = insertAtStart(head,99);
    printf("after Insertion the linked list:-\n");
    traversal(head);
    return 0;
}