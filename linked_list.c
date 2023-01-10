#include<stdio.h>
#include<stdlib.h>

// link list node
struct Node 
{
   int data;
   struct Node *next;
};

// link list traversal
void show_linkedlist(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;
    
    // allocating memory in heap
    head = (struct Node*) malloc(sizeof(struct Node));
    first = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    
    // linking head element to the first element 
    head->data = 11;
    (*head).next = first;
    // linking second element to the third
    first->data = 12;
    first->next = second;
    // linking second element to the third
    second->data = 13;
    second->next = third;
    // end of the linked list
    third->data = 14;
    third->next = NULL;

    show_linkedlist(head);
    return 0;
}