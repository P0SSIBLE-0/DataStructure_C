#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int size;
    int top;
    int* arr;
}stack;

int isFull(stack *ptr){
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(stack *ptr){
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
void push(stack *ptr,int value){
    if (isFull(ptr))
    {
        printf("Stack Overflow! , cannot %d in the Stack\n", value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(stack *ptr){
    if(isEmpty(ptr)){
        printf("stack is Underflow\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main(){
    stack *s = (stack*)malloc(sizeof(stack)); 
    s->size = 10;
    s->top = -1;
    s->arr = (int*) malloc(s->size*sizeof(int)); // creating Array dynamically
    push(s, 10); //  push the Element in the stack
    printf("%d\n", isEmpty(s)); // checking stack is Empty or Not
    printf("%d\n", s->arr[s->top]);
    printf("Popped %d from the stack\n", pop(s));
    return 0;
}