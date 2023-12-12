#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100

char infix[max];
char postfix[max];
char stack[max];
int top=-1;

int percedence(char symbol)
{
    switch(symbol)
    {
    case'^':
        return 3;
        break;
    case'*':
    case'/':
        return 2;
        break;
    case'+':
    case'-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}
void push(char symbol)
{
    if(top==max-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top]=symbol;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");

    }
    else
    {
        char c;
        c=stack[top];
        top--;
        return  c;
    }
}

int isEmpty()
{
    if (top==-1)
        return 0;
    else
        return 1;
}

int space(char symbol)
{
    if(symbol==' ' || symbol=='\t')
        return 0;
    else
        return 1;
}
void infix_to_postfix()
{
    char symbol,next;
    int j=0;
    int check;

    for(int i=0; i<strlen(infix); i++)
    {
        symbol=infix[i];
        if(space(symbol)!=0)
        {
            switch(symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while(isEmpty() && stack[top]!='(')
                    postfix[j++]=pop();
                pop();
                break;
            case'+':
            case'-':
            case'*':
            case'/':
            case'^':
                check=isEmpty();
                while(check!=0 &&  ( percedence(stack[top])>=percedence(symbol)))
                    postfix[j++]=pop();
                push(symbol);
                break;
            default:
                postfix[j++]=symbol;
                break;

            }
        }
    }
    while(isEmpty())
        postfix[j++]=pop();

}
void print_postfix()
{
    printf("Postfix Expression is :");
    for(int i=0; i<strlen(postfix); i++)
    {
        printf("%c",postfix[i]);
    }
    printf("\n");
}
int main()
{
    printf("Enter Infix Expression\n");
    gets(infix);
    infix_to_postfix();
    print_postfix();

}
