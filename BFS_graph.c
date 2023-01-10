#include<stdio.h>
#include<stdlib.h>

// breadth for searching in graph structure program.

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

int main(){
    // initializing the queue
    queue q;
    q.size = 20;
    q.front = -1;
    q.rear = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    // implementation of BFS
    int u , i = 1;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] ={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q,i); // enqueue for exploration
    while (!isEmpty(&q))
    {
        int node  = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q,j);
            }
        }
        
    }
    

    return 0;
}