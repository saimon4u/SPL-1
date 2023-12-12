#include<stdio.h>
struct node
{
    int freq;
    char alph;
    struct node*left,*right;
};

void print_array(int arr[],int index)
{
    for(int i=0;i<index;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
int is_leaf(struct node*root)
{
    if((root->left==NULL && root->right==NULL))
        return 0;
    else return 1;
}
void print_code(struct node*root,int arr[],int index)
{
    if(root->left)
    {
        arr[index]=0;
        print_code(root->left,arr,index+1);
    }
    if(root->right)
    {
        arr[index]=1;
        print_code(root->right,arr,index+1);
    }
    if(!is_leaf(root))
    {
        printf("%c:->  ",root->alph);
            print_array(arr,index);
    }

}
struct node*create_node(int freq,char alph)
{
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->freq=freq;
    new_node->alph=alph;
    new_node->left=NULL;
    new_node->right=NULL;

};

int main()
{
    int arr[100];
    int freq[]=  {1,3,4,10,12};
    char alph[]= {'n','s','t','a','i'};
    struct node*one=create_node(1,'n');
    struct node*three=create_node(3,'s');
    struct node*T1=create_node(4,'$');

    T1->left=one;
    T1->right=three;

    struct node*four=create_node(4,'t');
    struct node*T2=create_node(8,'$');

    T2->left=T1;
    T2->right=four;

    struct node*ten=create_node(10,'a');
    struct node*T3=create_node(18,'$');

    T3->left=T2;
    T3->right=ten;

    struct node*twelve=create_node(12,'i');
    struct node*T0=create_node(30,'$');

    T0->left=twelve;
    T0->right=T3;


    print_code(T0,arr,0);

   // printf("Root: TO->%d %c",T0->freq,T0->alph);

    return 0;
}
