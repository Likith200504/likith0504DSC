#include<stdio.h>
#include<ctype.h>
char stack[100];
int top=-1;
void push(char ele)
{
    top++;
    stack[top]=ele;
}
char pop()
{
    return stack[(top)--];
}
int pr(char op)
{
    switch(op)
    {
        case '#':return 0;
                break;
        case '(':return 1;
                break;
        case '+':return 2;
                break;
        case '-':return 2;
                break;
        case '*':return 2;
                break;
        case '/':return 2;
                break;
        default:return 0;
                break;
    }
}
void main()
{
    char infix[100], postfix[100];
    int i=0,count=0;
    char ch;
    //clrscr();
    printf("Enter your infix expression:");
    scanf("%s",infix);
    push('#');
    while (infix[i]!='\0')
    {
        if (isalpha(infix[i]))
        {
            postfix[count]=infix[i];
            count++;
        }
        else if(infix[i] == '(')
            push(infix[i]);
        else if(infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                ch=pop();
                postfix[count]=ch;
                count++;
            }
            pop(); /* Removing the ( */
        }
        else
        {
            while ((stack[top]!='#') && (pr(infix[i])<=pr(stack[top])))
            {
                ch=pop();
                postfix[count]=ch;
                count++;
            }
            push(infix[i]);
        }
        i++;
    }
    for(i=top;i!=0;i--)
    {
        if (stack[i] == '(')
            printf ("\n There was an issue with the expression...");
        ch=pop();
        postfix[count]=ch;
        count++;
    }

    for(i=0;i<count;i++)
    {
        printf("%c",postfix[i]);
    }
}
