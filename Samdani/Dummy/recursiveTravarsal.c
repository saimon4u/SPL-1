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

void preorder(struct tree *root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right); 
}

void inorder(struct tree *root) {
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct tree *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
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
    preorder(root);
    printf("\n\n");
    printf("Inorder travasal:");
    inorder(root);
    printf("\n\n");
    printf("Postorder travasal:");
    postorder(root);
    printf("\n\n");
    printf("Level order travasal:\n");
    level_order(n);

    return 0;
}