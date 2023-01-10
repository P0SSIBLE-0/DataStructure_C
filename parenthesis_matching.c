#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int size;
    int top;
    char arr;
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
void push(stack *ptr,char value){
    if (isFull(ptr))
    {
        printf("Stack Overflow! , cannot %d in the Stack\n", value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
char pop(stack* ptr){
    if(isEmpty(ptr)){
        printf("stack is Underflow\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int parenthesisMatch(char* exp){
    stack* sp;
    sp->size =90 ;
    sp->top = -1; 
    sp->arr = (char*) malloc(sp->size * sizeof(char));
    for (int i = 0;exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp,'(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;    
    
}

int main(){
    char* exp = " 5+5(4+2)";
    if (parenthesisMatch(exp))
    {
        printf("the parenthesis is matching\n");

    }
    else{
        printf("the parenthesis is not matching\n");
    }
    
    return 0;
}