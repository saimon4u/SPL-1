#include<stdio.h>
#include<malloc.h>

/* this is the tree
             5
           /   \
          4     3
         /     / \
        2     1   7 

preorder -> 5 4 2 3 1 7
inorder -> 2 4 5 1 3 7
postorder -> 2 4 1 7 3 5
*/

int n = 7;
int arr[7];
int front = 0,rear = 0;
struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree * create(){
    int choice;
    struct tree *node = (struct tree *) malloc (sizeof(struct tree));
    printf("1. Create a node\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter data: ");
        scanf("%d",&node->data);
        printf("Creating left child of %d:\n",node->data);
        node->left = create();
        printf("Creating right child of %d:\n",node->data);
        node->right = create();
        return node;
    }
    else{
        return NULL;
    }
}
void push(int val){
    if(rear==n){
        printf("Overflow!\n");
        return;
    }
    else{
        arr[rear] = val;
        rear++;
    }
}
int pop(struct tree *root){
    int value;
    if(front == n+1){
        return -1;
    }
    else{
        value = arr[front];
        front++;
    }
    return value;
}
void display(struct tree *root){
    if(root!=NULL){
        push(root->data);
        display(root->left);
        display(root->right);
    }
}
int main(){
    struct tree *root = create();
    printf("Tree: \n");
    display(root);
    for(int i=0; i<7; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}