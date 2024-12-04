#include <stdio.h>
#define MAX 5
void push(int stack[], int *top, int value)
{
    if (*top >= MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = value;
    printf("Pushed the value to the stack\n");
}
void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
    } else
    {
        printf("Popped the value\n");
        *top = *top - 1;
    }
}
void display(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    for (int i = 0; i <= *top; i++)
    {
        printf("Stack element: %d\n", stack[i]);
    }
}
int main()
{
    int stack[MAX];
    int top = -1;
    push(stack, &top, 3);
    push(stack, &top, 4);
    push(stack, &top, 5);
    display(stack, &top);
    pop(stack, &top);
    display(stack, &top);
    return 0;
}
