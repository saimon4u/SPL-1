#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>
#define SIZE 100


// Implementation of Circular Queue

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



// Implementation of Stack


typedef struct stack{
    int top,size,*items;
}stack;
stack *createStack(){
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->size = 100;
    s->items = (int *)malloc(sizeof(int)*s->size);
    return s;
}
bool StackEmpty(stack *s){
    return s->top == -1;
}
bool StackFull(stack *s){
    return s->top == SIZE-1;
}
void push(stack *s,int data){
    if(StackFull(s)) return;
    s->items[++s->top] = data;
}
int pop(stack *s){
    if(StackEmpty(s))return -1;
    int element;
    element = s->items[s->top--];
    return element;
}
void display(stack *s){
    for(int i=0; i<=s->top; ++i){
        printf("%d ",s->items[i]);
    }
    printf("\n");
}



// Implementation of Priority Queue


typedef struct MinHeap{
    int size,capacity,*arr;
}p_queue;
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



// Implementation of Map


typedef struct Map{
    int size;
    char **keys;
    int *values;
}map;
map *createMap(){
    map *m = (map *)malloc(sizeof(map));
    m->size = 0;
    m->keys =(char **)malloc(sizeof(char *)*SIZE);
    for(int i=0; i<SIZE; ++i)m->keys[i] = (char *)malloc(sizeof(char)*100);
    m->values = (int *)malloc(sizeof(int)*SIZE);
    return m;
}
int getIndex(map *m,char *key){
    for(int i=0; i<m->size; ++i){
        if(!strcmp(m->keys[i],key))return i;
    }
    return -1;
}
void insert(map *m,char *key,int value){
    printf("Inserted! %s at %d\n",key,m->size);
    if(m->size == SIZE -1) return;
    strcpy(m->keys[m->size],key);
    m->values[m->size] = value;
    m->size++;
}
int getValue(map *m,char *key){
    int index = getIndex(m,key);
    if(index==-1)return -1;
    return m->values[index];
}
char *getKey(map *m,int value){
    int index = -1;
    for(int i=0; i<m->size; ++i){
        if(m->values[i]==value){
            index = i;
            break;
        }
    }
    if(index==-1)return "";
    return m->keys[index];
}
void printMap(map *m){
    for(int i=0; i<m->size; ++i){
        printf("%s-->%d\n",m->keys[i],m->values[i]);
    }
}