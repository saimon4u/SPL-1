#include<stdio.h>
void enqueue(int *queue, int n);
void dequeue(int *queue);
void print();
int main(){
    int n,i,j;
    scanf("%d",&n);
    int array[n+1],queue[n],tree[(n*n)+n+1]={0};
    array[0]=0;
    for(i=1;i<n;i++){
        scanf("%d",&array[i]);
    }
    tree[0]=0;
    for(i=1;i<n;i++){

    }
    return 0;
}
void enqueue(int n){
    if(rear==size-1){
        printf("Overflow\n");
        return;
    }
    else if(rear==-1){
        front++;
        rear++;
    }
    queue[rear++]=n;
    printf("Enqueued element: %d\t",queue[rear]);
    printf("Front: %d\tRear: %d\n",front,rear);
}
void dequeue(){
    if(front==-1||front>rear){
        printf("Underflow\n");
        return;
    }
    printf("Dequeued elemnet: %d\t",queue[front++]);
    printf("Front: %d\tRear: %d\n",front,rear);
}
void print(){
    if(front==-1||front>rear){
        printf("Empty queue\n");
        return;
    }
    printf("Queue: ");
    for(int i=front;i<=rear;i++){
        printf("%d  ",queue[i]);
    }
    printf("\n");
}
