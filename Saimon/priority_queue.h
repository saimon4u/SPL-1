#include<stdio.h>
#include<malloc.h>
typedef struct MinHeap{
    int size,capacity,*arr;
}p_queue;
#define SIZE 100
p_queue *createPriorityQueue(){
    p_queue *p = (p_queue *) malloc(sizeof(p_queue));
    p->size = 0;
    p->capacity = SIZE;
    p->arr = (int *)malloc(sizeof(int)*p->capacity);
    return p;
}
void swap(int *a,int *b){
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}
void enqueueHelper(p_queue *p,int index){
    int parent = (index-1)/2;
    if(p->arr[parent] > p->arr[index]){
        swap(&p->arr[index],&p->arr[parent]);
        enqueueHelper(p,parent);
    }
}
void p_enqueue(p_queue *p,int data){
    if(p->size < p->capacity){
        p->arr[p->size] = data;
        enqueueHelper(p,p->size);
        p->size++;
    }
}
void heapify(p_queue *p,int index){
    int left = 2*index + 1;
    int right = 2*index + 2;
    int min = index;
    if(left >= p->size || left < 0) left = -1;
    if(right >= p->size || right < 0) right = -1;
    if(left!=-1 && p->arr[left] < p->arr[index])min = left;
    if(right!=-1 && p->arr[right] < p->arr[index])min = right;
    if(min!=index){
        swap(&p->arr[min],&p->arr[index]);
        heapify(p,min);
    }
}
int p_dequeue(p_queue *p){
    int element = p->arr[0];
    p->arr[0] = p->arr[p->size-1];
    p->size--;
    heapify(p,0);
    return element;
}