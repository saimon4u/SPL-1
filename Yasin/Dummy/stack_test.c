#include<stdio.h>
#include"stack.h"

int main(){
    stack* s = createStack(10);
    push(10,s);
    push(20,s);
    printf("%d ", pop(s));
}