#include<stdio.h>
#include<stdbool.h>
#define capasity 5
int queue[capasity];
int front=0;rear=-1;
int queue_size=0;

bool isempty()
{
    if (queue_size==0)
        return true;
        else
    return false;
}

bool isfull()
{
    if (queue_size==capasity)
    {
        return true;
    }
    else
        return false;
}

void enqueue(int x)
{
    if(isfull())
    {
        printf("queue is full\n");
        return ;
    }
    else {
        rear=((rear+1)%capasity);
        queue[rear]=x;
        queue_size++;
    }
}

int dequeue()
{
    if(isempty())
    {
        printf("queue is empty");
        return -1;
    }
    else {

        int item=queue[front];
        queue[front]=-1;
        front=(front+1)%capasity;
        queue_size--;
        return item;
    }
}
print_queue()
{
    printf("queue is : ");
    for(int i=0;i<capasity;i++)
    {
        printf("%d  ",queue[i]);
    }
    printf("\n");
}

int main(){
       enqueue(20);
       enqueue(10);
       enqueue(55);
       enqueue(55);
       printf("queue_size is %d\n",queue_size);
       print_queue();
       enqueue(56);
       enqueue(77);
       printf("Dequeue value : %d\n",dequeue());

       print_queue();
       printf("queue_size is %d\n",queue_size);
       printf("Dequeue value : %d\n",dequeue());
       print_queue();
}
