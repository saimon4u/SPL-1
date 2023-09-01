#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#define SIZE 100
typedef struct stack{
    int top,size,*items;
}stack;
stack *createStack(){
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->size = 100;
    s->items = (int *)malloc(sizeof(int)*s->size);
    return s;
}
bool StackEmpty(stack *s){
    return s->top == -1;
}
bool StackFull(stack *s){
    return s->top == SIZE-1;
}
void push(stack *s,int data){
    if(StackFull(s)) return;
    s->items[++s->top] = data;
}
int pop(stack *s){
    if(StackEmpty(s))return -1;
    int element;
    element = s->items[s->top--];
    return element;
}
void display(stack *s){
    for(int i=0; i<=s->top; ++i){
        printf("%d ",s->items[i]);
    }
    printf("\n");
}