#include<stdio.h>
#include<stdlib.h>

// intialization of queue(FIFO)
typedef struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
}queue;
// operations in queue
//1. isEmpty()
int isEmpty(queue *q){
    if(q->front==q->rear){
        return 1;
    }
    return 0;
}
//2. isFull()
int isFull(queue *q){
    if(q->rear == q->size-1){
        return 1;
    }
    return 0;
}
//3. enqueue() to push element into queue
void enqueue(queue * q,int val){
    if(isFull(q)){
        printf("Queue Overflow\n");
    }
    else{
        q->rear++;
        q->arr[q->rear]=val;
    }
}

//4. dequeue() to pop element from queue
int dequeue(queue* q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow\n");}
    else{
        q->front = q->front + 1;
        a=q->arr[q->front];
    }
    return a;
}
void traversalQueue(queue* q ){
    for (int i = q->front+1; i <= q->rear; i++)
    {
        printf("the %d element in queue is = %d\n", i+1 ,q->arr[i]);
    }
}
int main(){
    queue q;
    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int*)malloc(q.size * sizeof(int));
    enqueue(&q,32);
    enqueue(&q,45 );
    enqueue(&q,03 );
    dequeue(&q);
    traversalQueue(&q);
    return 0;
}