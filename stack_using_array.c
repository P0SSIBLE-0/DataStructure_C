#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
} stack;

int isEmpty(struct stack *ptr){
    if (ptr->top == -1) {
        return 1;
    }
    else{
        return 0;
    } 
}

int isFull(struct stack *ptr){
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    return 0;
}

int main(){
    stack *s = (stack*)malloc(sizeof(stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    if (isEmpty(s))
    {
        printf("The Stack is Empty");
    }
    else{
        printf("The stack is not Empty");
    }
    return 0;
}