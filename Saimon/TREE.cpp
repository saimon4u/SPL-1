#include <bits/stdc++.h>
using namespace std;
struct tree{
    int data;
    struct tree *left,*right;
};
struct tree* NewNode(int data){
    struct tree *node = (struct tree*)malloc(sizeof(struct tree));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct tree* create(int *arr,int i,int n){
    struct tree *root = NULL;
    if(i < n){
        root = NewNode(arr[i]);
        root->left = create(arr,(2*i+1),n);
        root->right = create(arr,(2*i+2),n);
    }
    return root;
}
void preorder(struct tree *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void Preorder (struct tree *root){
    if(root==NULL) return;
    stack <struct tree*> st;
    while(root!=NULL){
        cout << root->data << " ";
        if(root->right!=NULL) st.push(root->right);
        if(root->left!=NULL) root = root->left;
        else{
            if(!st.empty()){
                root = st.top();
                st.pop();
            }
            else root = NULL;
        }
    }
    cout << endl;
}
void Rearrange(int *from,int *to,int n){
    int mid = (n+0)/2;
    int i,k;
    i = k = mid;
    to[0] = from[mid];
    int j=1;
    while(j<n){
        to[j++] = from[--i];
        to[j++] = from[++k];
        // i--,k++;
    }
}
void Order(struct tree* root,int size){
    struct tree* stack[size];
    int top = 0;
    while(root!=NULL){
        printf("%d ",root->data);
        if(root->right !=NULL){
            stack[top++]=root->right;
        }
        if(root->left !=NULL){
            root=root->left;
        }
        else{
            if(top>0){
                root = stack[--top];
            }
            else root = NULL;
        }
    } 
}
void inorder(struct tree *root){
    if(root!=NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void Inorder(struct tree *root){
    stack<struct tree *> st;
    while (root!=NULL || st.empty() == false){
        while (root!=NULL){
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        cout << root->data << " ";
        root = root->right;
    }
}
void postorder(struct tree *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
void Postorder(struct tree *root){
    if(root == NULL) return;
    stack<struct tree *> s1, s2;
    s1.push(root);
    struct tree *node;
    while (!s1.empty()){
        node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()){
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}
void poostorder(struct tree* root, int size){
    struct tree *stk1[1000]={NULL},*stk2[1000]={NULL},*ptr;
    ptr=root;
    int top1=0,top2=0;
    while(ptr->left!=NULL && ptr->right!=NULL){
    stk1[top1++]=ptr;
    while(top1>0){
    
    ptr=stk1[--top1];//pop
    

    stk2[top2++]=ptr;//push to stack 2
    if(ptr->left !=NULL)
    {stk1[top1++]=ptr->left;}
    if(ptr->right !=NULL){
    stk1[top1++]=ptr->right;
    }
   
    //ptr=ptr->left;
    }
    }
  
     while (top2 > 0) {
        struct tree *node = stk2[--top2];
        printf("%d ", node->data);
    }


}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    /*
                       1

               2               3

          4        5       6      7

        8   9   10  11  12  13  14  15

        preorder -> 1 2 4 8 9 5 10 11 3 6 12 13 7 14 15
        inorder -> 8 4 9 2 10 5 11 1 12 6 13 3 14 7 15

                     15

               14            13

          12      11      10      9

        8   7   6   5   4   3   2   1

        preorder -> 15 14 12 8 7 11 6 5 13 10 4 3 9 2 1

                      8

                7             9

           6      10      5       11

        4   12  3   13  2   14  1   15

        preorder -> 8 7 6 4 12 10 3 13 9 5 2 14 11 1 15

    */
    int n = sizeof(arr)/sizeof(arr[0]);
    struct tree *root = create(arr, 0, n);
    cout << "1st tree traversal: " << endl;
    // preorder(root);
    // cout << endl;
    // Preorder(root);
    // sort(arr,arr+n,greater<int>());
    // root = create(arr,0,n);
    // cout << "2nd tree traversal: " << endl;
    // preorder(root);
    // cout << endl;
    // Preorder(root);
    // int Third[n];
    // Rearrange(arr,Third,n);
    // root = create(Third,0,n);
    // cout << "3rd tree traversal: " << endl;
    // preorder(root);
    // cout << endl;
    // Preorder(root);
    // inorder(root);
    // cout << endl;
    // Inorder(root);
    // postorder(root);
    // cout << endl;
    Postorder(root);
    cout << endl;
    poostorder(root,n);
    return 0;
}
 