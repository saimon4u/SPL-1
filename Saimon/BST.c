#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct BST{
    int data;
    struct BST *left,*right;
}binary;
binary* createNode(int value){
    binary *node = (binary *) malloc(sizeof(binary));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}
void link(binary *root,int value){
    binary *new = createNode(value);
    while(root!=NULL){
        if(root->data >= new->data){
            if(root->left == NULL){
                root->left = new;
                break;
            }
            else root = root->left;
        }
        else{
            if(root->right == NULL){
                root->right = new;
                break;
            }
            else root = root->right;
        }
    }
}
bool search(int data,binary *root){
    if(root==NULL) return false;
    if(data == root->data)return true;
    else if(data > root->data)search(data,root->right);
    else if(data < root->data)search(data,root->left);
}
void insert(int data,binary *root){
    if(data <= root->data){
        if(root->left == NULL){
            binary *new = createNode(data);
            root->left = new;
            return;
        }
        else insert(data,root->left);
    }
    else{
        if(root->right == NULL){
            binary *new = createNode(data);
            root->right = new;
            return;
        }
        else insert(data,root->right);
    }
}
binary* minValueNode(binary *node){
    binary *current = node;
    while (current && current->left != NULL)current = current->left;
    return current;
}
binary* delete(int data,binary *root,bool *flag){
    if(root == NULL)return root;
    if(data < root->data)root->left = delete(data,root->left,flag);
    else if(data > root->data)root->right = delete(data,root->right,flag);
    else{
        if(root->left == NULL) {
            binary *temp = root->right;
            free(root);
            *flag = true;
            return temp;
        }
        else if(root->right == NULL) {
            binary *temp = root->left;
            free(root);
            *flag = true;
            return temp;
        }
        binary* temp = minValueNode(root->right); // here we can find both maximum of left tree or minimum of right tree
        root->data = temp->data;
        root->right = delete(temp->data,root->right,flag);
    }
    return root;
}
void Inorder(binary *root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}
int main(){
    int arr[] = {34,63,87,25,121,11,75,31,87,42,57,23,16,24,11,67,21,97,32};
    int size = sizeof(arr)/sizeof(int);
    binary *root = createNode(arr[0]);
    for(int i=1; i<size; ++i){
        link(root,arr[i]);
    }
    Inorder(root);
    printf("\n");
    // int data = 121;
    // if(search(data,root))printf("%d found\n",data);
    // else printf("%d not found\n",data);
    // insert(100,root);
    // insert(30,root);
    // Inorder(root);
    // printf("\n");
    bool flag = false;
    root = delete(121,root,&flag);
    if(flag)printf("Deleted\n");
    else printf("Can't delete\n");
    Inorder(root);
    printf("\n");
    return 0;
}