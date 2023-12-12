#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node*top=NULL;

struct node*pop(struct node*top)
{
    if(top==NULL)
        printf("Stack is Empty can't pop\n");
    else if(top->next==NULL)
    {
        struct node*temp;
        temp=top;
        top=NULL;
        free(temp);
    }
    else
    {
        struct node*temp;
        temp=top;
        top=top->next;
        free(temp);
    }
    return top;
}
void print_stack()
{
    if(top==NULL)
    {
        printf("Oops! Stack is Empty\n");

    }
    else
    {
        struct node*temp;
        temp=top;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}
void push(int item)
{
    struct node*node;
    node=(struct node*)malloc(sizeof(struct node));
    node->data=item;
    node->next=NULL;
    if(top==NULL)
    {
        top=node;
    }
    else
    {
        node->next=top;
        top=node;
    }
}
int main()
{
    struct node*new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=10;
    new_node->next=NULL;
    top=new_node;
    push(30);
    print_stack();
    push(40);
    print_stack();
    push(50);
    print_stack();
    top= pop(top);
    print_stack();
    top= pop(top);
    print_stack();
    top= pop(top);
    top= pop(top);
    print_stack();
    push(100);
    push(200);
    print_stack();


    return 0;
}
