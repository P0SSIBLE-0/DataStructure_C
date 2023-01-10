#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
// Insert At the beginning 
struct Node* insertatstart(struct Node* head , int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr; // it will gonna return new head.
};
// Insert at the End of the list
struct Node* insertAtEnd(struct Node* head , int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head;
    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
};

// Insert after The given Node
struct Node* insertAfterNode(struct Node* head, struct Node* prevNode , int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    
    return head;
};

// Insert after at the between
struct Node* insertatindex(struct Node* head , int data, int index)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head;
    int i = 1;
    while (i!= index-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
};

// Traversing the linked list
void show_list(struct Node* ptr){
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    
}

int main(){
    struct Node* first;
    struct Node* second;
    struct Node* third;
    first = (struct Node* ) malloc(sizeof(struct Node));
    second = (struct Node* ) malloc(sizeof(struct Node));
    third = (struct Node* ) malloc(sizeof(struct Node));

    first->data = 21;
    first->next = second;

    second->data = 25;
    second->next = third;

    third->data = 29;
    third->next = NULL;

    first = insertatstart(first, 55);
    printf("Insert Elememt at the beginning:\n");
    show_list(first);
    first = insertatindex(first, 11, 2);
    printf("Insert Element at the between:\n");
    show_list(first);
    first = insertAtEnd(first, 35);
    printf("Insert Element at the End:\n");
    show_list(first);
    first = insertAfterNode(first, third, 99);// here we are inserting the 99 after the third Node.
    printf("Insert Element After A Node:\n");
    show_list(first);


    return 0;
}