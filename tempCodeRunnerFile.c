#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

int main(void) {
  struct Node *head=0, *temp;
  int choice, count = 0;
  while (choice) {
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter the data of the node: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head == 0) {
      temp = head = newnode;
       temp->next = newnode;
      temp = newnode;
    } else {
      temp->next = newnode;
      temp = newnode;
    }
    
    printf("DO you want to continue (1/0)");
    scanf("%d", &choice);
    
    count++;
  }
  temp = head;
    
  while (temp!=0) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("no. of node is %d", count);

  return 0;
}