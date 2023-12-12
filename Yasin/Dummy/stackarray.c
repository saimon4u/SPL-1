#include<stdio.h>
#include<stdlib.h>
struct stack{
    int capacity;
    int top;
    int *array;
};
struct stack *createStack(int capacity){
    struct stack *st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    st->capacity=capacity;
    st->array=(int*)malloc(capacity*sizeof(int));
    return st;
}
int isEmpty(struct stack *st){
    if(st->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *st){
    if(st->top==st->capacity-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack *st,int x){
    if(isFull(st)){
        printf("Sorry, stack is full.\n");
    }
    else{
        st->array[++st->top]=x;
    }
}
void pop(struct stack *st){
    if(isEmpty(st)){
        printf("Sorry, stack is empty.\n");
    }
    else{
        st->top--;
    }
}
void display(struct stack *st){
    if(isEmpty(st)){
        printf("Sorry, stack is empty.\n");
    }
    else{
        printf("Stack: ");
        for(int i=0;i<=st->top;i++){
            printf("%d\t",st->array[i]);
        }
        printf("\n");
    }
}
int peek(struct stack *st){
    if(isEmpty(st)){
        printf("Sorry, stack is empty.\n");
    }
    else{
        printf("Top: %d\n",st->array[st->top]);
    }
}
int main(){
    struct stack *st=createStack(5);
    return 0;
}