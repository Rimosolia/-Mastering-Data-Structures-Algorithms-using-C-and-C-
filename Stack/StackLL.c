#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp==NULL)
    {
        printf("Stack is full\n");
        return;
    }

    temp->data = x;
    temp->next = top;
    top = temp;
}
int pop()
{
    if (top==NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    int x = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return x;
}
void Display()
{
    struct Node *temp = top;
    while (temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    Display();
    printf("\n");
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}