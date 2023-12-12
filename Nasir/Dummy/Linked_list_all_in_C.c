//linked_list in_C
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;

};

struct node*delate_first_node(struct node*head)
{
    if(head==NULL)
    {
        printf("Linked list is already Empty");

    }
    else
    {
        struct node*temp;
        temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
    return head;
};

struct node*delate_node_at_given_position(struct node*head,int position)
{
    if(head==NULL)
    {
        printf("Linked list is Empyty\n");
        return head;
    }
    else if (position==1)
    {
        head=delate_first_node(head);
        return head;
    }
    else
    {
        struct node*temp,*previous;
        temp=head;
        while(position!=1)
        {
            previous=temp;
            temp=temp->next;
            position--;
        }
        previous->next=temp->next;
        free(temp);
        return head;
    }

}
struct node*delate_last_node(struct node*head)
{
    if(head==NULL)
        printf("There is no node is the linked list\n");
    else if(head->next==NULL)
        free(head);
    else
    {
        struct node*temp;
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;

    }
    return head;
};


void insert_node_at_given_position(struct node*head,int position,int item)
{
    struct node*temp,*node;
    temp=head;
    node=(struct node*)malloc(sizeof(struct node));
    node->data=item;
    node->next=NULL;
    while(position!=2)
    {
        temp=temp->next;
        position--;
    }
    node->next=temp->next;
    temp->next=node;
}

/* void  insert_node_at_begin(struct node**head,int item)
{
     struct node*node;
       node=(struct node*)malloc(sizeof(struct node));
       node->data=item;
       node->next=*head;
       *head=node;
}*/
struct node* insert_node_at_begin(struct node*head,int item)

{
    struct node*node;
    node=(struct node*)malloc(sizeof(struct node));
    node->data=item;
    node->next=head;
    head=node;

    return head;
}

void insert_node_at_end(struct node*head,int item)
{
    struct node*temp,*node;
    node=(struct node*)malloc(sizeof(struct node));

    node->data=item;
    node->next=NULL;
    temp=head;


    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=node;
}



void print_list(struct node*head)
{
    struct node*temp;
    temp=head;
    if(temp==NULL)
    {
        printf("Linked is is empty\n:");
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void count_number_of_nodes(struct node*head)
{
    int count=0;
    struct node*temp;
    temp=head;
    if(temp==NULL)
    {
        printf("No nodes\n:");
        return ;
    }
    else
    {
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
    }
    printf("Total number of nodes %d\n",count);
    return;
}
int main()
{
    struct node *head;
    head=NULL;
    head=(struct node*)malloc(sizeof(struct node));

    head->data=10;
    head->next=NULL;
    struct node*current_node;
    current_node=(struct node*)malloc(sizeof(struct node));
    current_node->data=20;
    current_node->next=NULL;

    head->next=current_node;

    current_node=(struct node*)malloc(sizeof(struct node));

    current_node->data=30;
    current_node->next=NULL;

    head->next->next=current_node;

    print_list(head);

    count_number_of_nodes(head);

    insert_node_at_end(head,40);
    insert_node_at_end(head,50);
    insert_node_at_end(head,60);
    insert_node_at_end(head,70);

    //must have return type because pass by value
    //another process pass by reference is i insert_node_at_begin(&head,4);

    head= insert_node_at_begin(head,5);
    print_list(head);
    insert_node_at_given_position(head,3,15);
    print_list(head);

    insert_node_at_given_position(head,5,25);
    print_list(head);

    head=delate_first_node(head);


    print_list(head);

    head=delate_last_node(head);
    print_list(head);
    head=delate_node_at_given_position(head,7);
    print_list(head);

    count_number_of_nodes(head);

    return 0;
}
