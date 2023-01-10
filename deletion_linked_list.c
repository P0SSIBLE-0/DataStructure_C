#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
// 1. Delete The First Element(head) of the linked list:
struct Node* del_head(struct Node* head)
{
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
};
//2. Delete A Node at given index:
struct Node* del_at_index(struct Node* head, int index){
    struct Node* p = head;
    struct Node* q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    
    return head; 
}

//3. delete The Last Node:
struct Node* del_last(struct Node* head){
    struct Node* p = head;
    struct Node* q = head->next;
    while (q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// 4. delete the Node at given value
struct Node* del_at_value(struct Node* head, int value){
    struct Node* p = head;
    struct Node* q = head->next;
    while (q->data != value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head; 
}
void show_list(struct Node* ptr){
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next; 
    }
    printf("\n");
    
}

int main(){
    struct Node* head;  
    struct Node* second; 
    struct Node* third;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 100;
    head->next = second;

    second->data = 200;
    second->next = third;

    third->data = 300;
    third->next = NULL;
    show_list(head);

    // head = del_head(head);// Deleting the first node of the linked list
    //show_list(head);
    
    // head = del_at_index(head, 2);
    // show_list(head);

    // head = del_last(head);
    // show_list(head);

    head = del_at_value(head,200);
    show_list(head);
    return 0;
}