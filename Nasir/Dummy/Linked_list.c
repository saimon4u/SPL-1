#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node*create_node(int item,struct node*head)
{
    struct node*new_node=NULL;
     new_node=(struct node*)malloc(sizeof(struct node));

    new_node->data=item;
    new_node->next=NULL;

    if(head==NULL)
    {
      head->next=new_node;
    }
    else{
        while(head->next!=NULL)
        {
            head=head->next;
        }
        head->next=new_node;

    }
  return new_node;
};

int main()
{
    struct node *head;
    head=NULL;
    head=(struct node*)malloc(sizeof(struct node));

    head=create_node(10,head);
    create_node(20,head);

    printf("%d ",head->data);
    printf("%d",head->next->data);

    return 0;
}
