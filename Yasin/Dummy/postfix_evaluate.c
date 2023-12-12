#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct stack{
    int capacity;
    int top;
    int *exp;
};
struct stack *createStack(int capacity){
    struct stack *st=(struct stack*)malloc(sizeof(struct stack));
    st->capacity=capacity;
    st->top=-1;
    st->exp=(int *)malloc(capacity*sizeof(int));
    return st;
}
void push(struct stack *st,int n){
    st->exp[++st->top]=n;
    //printf("Pushed: %d\n",n);
}
char pop(struct stack *st){
    //printf("Popped: %d\n",st->exp[st->top]);
    return st->exp[st->top--];
}
void display(struct stack *st){
    printf("Stack: ");
    for(int i=0;i<=st->top;i++){
        printf("%d ",st->exp[i]);
    }
    printf("\n");
}
int peek(struct stack *st){
    return st->exp[st->top];
}
int postfixEvaluate(char *exp){
    struct stack *st=createStack(strlen(exp));
    int i;
    for(i=0;i<strlen(exp);i++){
        if(isdigit(exp[i])){
            push(st,exp[i]-'0');
        }
        else{
            int val1=pop(st),val2=pop(st);
            switch(exp[i]){
                case '+':
                    push(st,val1+val2);
                    break;
                case '-':
                    push(st,val2-val1);
                    break;
                case '*':
                    push(st,val1*val2);
                    break;
                case '/':
                    push(st,val2/val1);
                    break;
            }
        }
        //display(st);
    }
    return peek(st);
}
int main(){
    char exp[]="56+84/-";
    printf("%d\n",postfixEvaluate(exp));
    return 0;
}