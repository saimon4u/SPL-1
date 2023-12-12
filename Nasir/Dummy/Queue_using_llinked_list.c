#include<stdio.h>
struct node
{
    int data;
    struct node*next;
};
struct node*front=NULL,*rear=NULL;

void push(int item)
{
    struct node*node=(struct node*)malloc(sizeof(struct node));
    node->data=item;
    node->next=NULL;
    if(rear==NULL && front==NULL)
    {
        front=node;
        rear=node;
    }
  //  else if(rear!=NULL)
   // {
        rear->next=node;
        rear=node;
    //}
}

void pop()
{
    if(front==NULL)
        printf("Queue is Empty\n");
        else if(front->next==NULL)
        {
            front=front->next;
            rear=rear->next;
        }
    else{
        struct node*temp;
        temp=front;
        front=front->next;
        free(temp);
    }
}
void print_queue()
{
    struct node*temp;
    temp=front;
    if(temp==NULL){
        printf("Oops ! Queue is Empty\n");\
        return;
    }
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
   // struct node*new_node;
   // new_node=(struct node*)malloc(sizeof(struct node));
   // new_node->data=10;
    //new_node->next=NULL;
    //front=new_node;
    //rear=new_node;
    push(20);
    push(30);
    push(40);
    print_queue();

    pop();
    print_queue();

    pop();
    print_queue();
    pop();

    print_queue();
    pop();
    pop();
    print_queue();
    pop();
    print_queue();

    push(50);
    push(60);
        print_queue();

    push(70);
    print_queue();
    push(100);
    print_queue();


   return 0;

}
