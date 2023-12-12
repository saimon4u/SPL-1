#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty( struct stack *ptr)
{
    if ( (ptr->top) == -1 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int isFull( struct stack *ptr)
{
    if ( ptr->top == ptr->size-1 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void push(struct stack *ptr,int value){
    if(isFull(ptr)){
        printf("Stack Overflow!\nCannot push the value %d\n", value);
    }else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        //return -1;
        printf("Empty stack , Can't pop.\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int position){
    int arrIndex = ( ptr->top - position + 1 );
    if( arrIndex < 0 ){
        printf("Not a valid position!\n");
    }else{
        return ptr->arr[arrIndex];
    }
}

int stackTop(struct stack* s){
    return s->arr[s->top];
}

int stackBottom(struct stack *s){
    return s->arr[0];
}

int main()
{
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1; //since, at this point there is no element in the stack
    sp->arr = (int *) malloc(sizeof(int) * sp->size);
    printf("Stack Created successfully!\n");

    printf("Before pushing: Full? %d and Empty? %d\n",isFull(sp),isEmpty(sp));
    push(sp,10);
    push(sp,20);
    push(sp,30);
    push(sp,40);
    push(sp,50);
    push(sp,60);
    push(sp,70);
    push(sp,80);
    push(sp,90);
    push(sp,100);
    // push(sp,110);
    // push(sp,210);

    printf("After pushing: Full? %d and Empty? %d\n",isFull(sp),isEmpty(sp));

    // printf("%d popped from the stack\n", pop(sp));
    // printf("%d popped from the stack\n", pop(sp));
    // printf("%d popped from the stack\n", pop(sp));
    // printf("%d popped from the stack\n", pop(sp));

    // printf("%d is at the top of the stack\n", stackTop(sp));
    // printf("%d is at the bottom of the stack\n", stackBottom(sp));

    // printf("%d popped form the stack\n", pop(sp));
    // printf("%d popped form the stack\n", pop(sp));
    // printf("%d popped form the stack\n", pop(sp));    
    // printf("%d popped form the stack\n", pop(sp));
    // printf("%d popped form the stack\n", pop(sp));
    // printf("%d popped form the stack\n", pop(sp));    
    // printf("%d popped form the stack\n", pop(sp));  

    for(int i = 0; i < sp->size; i++){
        printf("Value at position %d is : %d\n", i+1, peek(sp, i+1));
    }  
    printf("%d is at the top of the stack\n", stackTop(sp));
    printf("%d is at the bottom of the stack\n", stackBottom(sp));


    return 0;
}