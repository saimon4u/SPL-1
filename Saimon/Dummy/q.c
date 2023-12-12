#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct Queue{
    int data;
    struct Queue *next;
}queue;

queue *front = NULL;
queue *createQueue(){
    queue *q = malloc(sizeof(queue));
    q->data = 0;
    q->next = NULL;
    return q;
}
void enqueue(int data){
    queue *q = createQueue(data);
    q->data = data;
    if(front == NULL){
        front = q;
        return;
    }
    queue *ptr = front;
    while(ptr->next!=NULL)ptr=ptr->next;
    ptr->next = q;
}
int dequeue(){
    int item = front->data;
    queue *ptr = front;
    front = front->next;
    free(ptr);
    return item;
}
bool QueueEmpty(){
    return front == NULL;
}