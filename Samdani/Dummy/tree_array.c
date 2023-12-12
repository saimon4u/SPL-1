#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree *root=NULL;


struct tree* createTreeFromArray(int arr[], int index, int n) {
    if (index >= n) {
        return NULL;
    }
    
    struct tree* newNode = (struct tree*)malloc(sizeof(struct tree));
    if(arr[index]==-1) return 0;
    newNode->data = arr[index];
    newNode->left = createTreeFromArray(arr, 2 * index + 1, n);
    newNode->right = createTreeFromArray(arr, 2 * index + 2, n);

    return newNode;
}

void preorder(int size)
{
    struct tree *stack[size];
    int top=-1;
    if(root==NULL)
    return;
    
    stack[++top]= root;
    while(top>=0)
    {
        struct tree *temp = stack[top--];
        printf("%d ", temp->data);
        if(temp->right!=NULL)
        stack[++top]=temp->right;
        if(temp->left!=NULL)
        stack[++top]=temp->left;
    }
}

void inorder(int size) {
    struct tree* Stack[size],*current;
    int top=-1;
    current=root;
    while (current != NULL || top!=-1) {
        while (current != NULL) {
            Stack[++top]=current;
            current = current->left;
        }
        current = Stack[top--]; 
        printf("%d ", current->data);
        current = current->right;
    }
}

void postorder(int size){
    struct tree *stack[size],*current, *lastvisited,*peek;
    int top=-1;
    current=root;
    lastvisited=NULL;


    while(current!=NULL || top!=-1){
        while(current!=NULL){
            stack[++top]=current;
            current=current->left;

        }
        peek=stack[top];
        if(peek->right==NULL || peek->right==lastvisited){
            printf("%d ",peek->data);
            lastvisited=peek;
            top--;
        }else{
            current=peek->right;
        }

    }
}

void level_order(int size)
{
    struct tree *queue[size];
    int front=0,rear=0,level=1;
    if(root==NULL)
    return;
    queue[rear++]=root;
    
    while(front<rear)
    {
        struct tree *temp = queue[front++];
        printf("%d ", temp->data);
        level--;
        
        if(temp->left!=NULL)
        queue[rear++]=temp->left;
        if(temp->right!=NULL)
        queue[rear++]=temp->right;
        if(level==0){
        printf("\n");
        level = rear-front;
        }
    }
}

int main() {
    int arr[] = {25,15,30,10,20,-1,40};
    int n = sizeof(arr) / sizeof(arr[0]);

    root = createTreeFromArray(arr, 0, n);

    
    printf("\nPreorder travasal:");
    preorder(n);
    printf("\n\n");
    printf("Inorder travasal:");
    inorder(n);
    printf("\n\n");
    printf("Postorder travasal:");
    postorder(n);
    printf("\n\n");
    printf("Level order travasal:\n");
    level_order(n);

    return 0;
}