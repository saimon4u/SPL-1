#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#define SIZE 100
typedef struct queue{
    int front,rear,size,*items;
}queue;
queue *createQueue(){
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    q->size = SIZE;
    q->items = (int*) malloc(sizeof(int) * q->size);
    return q;
}
bool QueueEmpty(queue *q){
    return q->front == -1;
}
bool QueueFull(queue *q){
  if ((q->front == q->rear + 1) || (q->front == 0 && q->rear == SIZE - 1)) return true;
  return false;
}
void enqueue(queue *q,int data){
    if(QueueFull(q))return;
    if(q->front == -1)q->front = 0;
    q->rear = (q->rear+1)%SIZE;
    q->items[q->rear] = data;
}
int dequeue(queue *q){
    int element;
    if(QueueEmpty(q)) return -1;
    element = q->items[q->front];
    if(q->rear == q->front){
        q->front = -1;
        q->rear = -1;
    }
    else q->front = (q->front+1)%SIZE;
    return element;
}
// void display(queue *q){
//   int i;
//   if(QueueEmpty(q))printf(" \n Empty Queue\n");
//   else{
//     printf("\n Front -> %d ",q->front);
//     printf("\n Items -> ");
//     for (i = q->front; i != q->rear; i = (i + 1) % SIZE) {
//       printf("%d ", q->items[i]);
//     }
//     printf("%d ", q->items[i]);
//     printf("\n Rear -> %d \n", q->rear);
//   }
// }