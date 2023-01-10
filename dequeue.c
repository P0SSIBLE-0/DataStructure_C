#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
} queue;

int is_empty(queue *q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}
int is_full(queue *q){
    if (q->rear == q->size-1)
    {
        return 1;
    }
    return 0; 
}

void enqueue_rear(queue *q, int data){
    if(is_full(q)){
        printf("Queue is full\n");
    }
    else{
        q->rear++;
        q->arr[q->rear] = data;
    }
};
int dequeue_rear(queue* q){
    int a = -1;
    if(is_empty(q)){
        printf("Queue Underflow\n");
    }
    else{
        q->rear = q->rear - 1;
        a =q->arr[q->rear];
    }
    return a;
};
void traversalQueue(queue* q ){
    for (int i = q->front+1; i <= q->rear; i++)
    {
        printf("the %d element in queue is = %d\n", i+1 ,q->arr[i]);
    }
}
int main()
{
    queue q;
    q.size = 10;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue_rear(&q,45 );
    enqueue_rear(&q,03 );
    enqueue_rear(&q,32);
    enqueue_rear(&q,99 );
    dequeue_rear(&q); // remove the last element from the queue
    traversalQueue(&q);
    return 0;
}