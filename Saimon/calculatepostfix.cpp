#include<iostream>
#include<string.h>
using namespace std;
struct stack{
    int top;
    int capacity;
    int * array;
};
struct stack *createstack(int capacity){
    struct stack * stack = (struct stack *) malloc (sizeof(struct stack));
    stack->top=-1;
    stack->capacity = capacity;
    stack->array = (int *) malloc (stack->capacity *sizeof(int));
    return stack;
}
int isEmpty(struct stack *stack){
    return stack->top == -1;
}
void push(struct stack *stack , char top){
    stack->array[++stack->top]=top;
}
char pop(struct stack *stack){
    if(!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}
int evaluate(char *exp){
    struct stack *stack = createstack(strlen(exp));
    int i;
    for(i=0; exp[i]; i++){
        if(isdigit(exp[i])){
            push(stack,exp[i]-'0');
        }
        // else if(exp[i]==' ');
        else{
            int value1 = pop(stack);
            int value2 = pop(stack);
            switch(exp[i]){
                case '+':
                    push(stack,value2+value1);
                    break;
                case '-':
                    push(stack,value2-value1);
                    break;
                case '*':
                    push(stack,value2*value1);
                    break;
                case '/':
                    push(stack,value2/value1);
                    break;
            }
        }
    }
    return pop(stack);
}
int main(){
    char exp[100]="562+*84/-";
    // for(int i=0; i<16; i++){
    //     cin >> exp[i];
    // }
    cout << "result: " << evaluate(exp) << endl;
    char temp[3]="12";
    cout << atoi(temp) << endl;
    return 0;
}

