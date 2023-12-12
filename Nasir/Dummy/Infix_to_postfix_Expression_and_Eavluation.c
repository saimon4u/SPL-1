#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100

char infix[max];
char postfix[max];
int stack[max];
int top=-1;

int postfix_Evaluation()
{
    for(int i=0;i<strlen(postfix);i++)
    {
        if((postfix[i]-'0')>=0 && (postfix[i]-'0')<=9)
            push(postfix[i]-'0');

    else {
        int a=pop();
        int b=pop();
        switch(postfix[i])
        {
        case '+':
            push(b+a);
            break;
        case'-':
          push(b-a);
          break;
        case'*':
            push(b*a);
            break;
        case'/':
            push(b/a);
            break;
        case'^':
            push(pow(b,a));
            break;

        }
    }
}
return pop();
}
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
void push(int symbol)
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
int  pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");

    }
    else
    {
        int  c;
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
    int ans=postfix_Evaluation();
    printf("Evaluation of postfix Expression is : %d ",ans);
    return 0;

}
/*
7+5*3/5^1+(3-2)
*/

