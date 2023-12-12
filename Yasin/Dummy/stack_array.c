#include<stdio.h>
#define size 10
int top=-1;
int stack[size];
void push(int x){
    if(top==size-1){
        printf("Stack is overflowed.\n");
    }
    else{
        stack[++top]=x;
    }
}
void pop(){
    if(top<0){
        printf("Stack is underflowed.\n");
    }
    else{
        top--;
    }
}
void display(){
    if(top<0){
        printf("Stack is underflowed.\n");
    }
    else{
        printf("Stack: ");
        for(int i=top;i>=0;i--){
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}
void peek(){
    if(top<0){
        printf("Stack is underflowed.\n");
    }
    else{
        printf("Top: %d\n",stack[top]);
    }
}
int main(){
    push(5);
    push(7);
    push(2);
    push(4);
    push(4);
    push(6);
    display();
    pop();
    display();
    return 0;
}