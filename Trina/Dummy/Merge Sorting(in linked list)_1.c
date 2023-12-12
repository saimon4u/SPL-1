#include<stdio.h>
#include<stdlib.h>


struct node
{
    int num;
    struct node*next;
};


struct node *stack,*head,*temp;



struct node*creation()
{

    struct node *stack,*head,*temp;
    head=0;
    int option,i;

    printf("How much time you wanna continue?");

     freopen("lovebabbar.txt","r",stdin);
    scanf("%d",&option);

    for(i=1; i<=option; i++)
    {


        stack=(struct node*)malloc(sizeof(struct node));



        scanf("%d",&stack->num);
        stack->next=0;

        if(head==0)head=temp=stack;

        else
        {
            temp->next=stack;
            temp=stack;
        }

    }

    return head;
}




void display(struct node*head)
{
    temp=head;
    while(temp)
    {
        printf("%d\t",temp->num);
        temp=temp->next;
    }
}



struct node* findmid(struct node* head)
{
    struct node* slow=head;
    struct node* fast=head->next;

    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}




struct node* mergesort(struct node* left,struct node* right)
{

    struct node* newhead=NULL;
    struct node* s;
    if(left==NULL)return right;
    if(right==NULL)return left;

    if(left!=NULL&&right!=NULL)
    {
        if(left->num<=right->num)
        {
            s=left;
            left=s->next;
        }
        else
        {
            s=right;
            right=s->next;
        }
    }
    newhead=s;

    while(left!=NULL&&right!=NULL)
    {
        if(left->num<=right->num)
        {
            s->next=left;
            s=left;
            left=s->next;
        }
        else
        {
            s->next=right;
            s=right;
            right=s->next;
        }
    }

    while(left!=NULL)
    {

        s->next=left;
        s=left;
        left=s->next;
    }


    while(right!=NULL)
    {

        s->next=right;
        s=right;
        right=s->next;
    }


    return newhead;


}




struct node*merge(struct node* head)
{

    if(head==NULL||head->next==NULL)return head;


    struct node* mid=findmid(head);


    struct node* left=head;
    struct node* right=mid->next;
    mid->next=NULL;

    left=merge(left);

    right=merge(right);

    struct node* result=mergesort(left,right);

    return result;




}



int main(void)
{

    struct node*head=creation();

    display(head);

    struct node*ptr=merge(head);

    printf("\n");

    display(ptr);





}
