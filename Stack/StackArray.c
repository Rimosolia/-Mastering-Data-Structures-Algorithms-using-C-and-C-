#include <stdio.h>
#include <stdlib.h>


struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));   
}

void Display(struct Stack st)
{
    int i;
    for (i = st.top; i>=0; i--)
    {
        printf("%d ", st.S[i]);
    }
}

void Push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack is full\n");
        return;
    }
    st->top++;
    st->S[st->top] = x;
}

int Pop(struct Stack *st)
{
    int x=-1;
    if (st->top == -1)
    {
        printf("Stack is empty\n");
        return x;
    }
    x = st->S[st->top--];
    return x;

}

int Peek(struct Stack st, int index)
{
    if (index > st.top)
    {
        printf("Index is out of range\n");
        return -1;
    }
    return st.S[index];
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}
 
int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
    {
        return 1;
    }
    return 0;
}

int stackTop(struct Stack st)
{
    if (st.top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return st.S[st.top];
}

int main()
{
    struct Stack st;
    create(&st);
    Push(&st, 1);
    Push(&st, 2);
    Push(&st, 3);
    Push(&st, 4);
    Push(&st, 5);
    Push(&st, 6);
    Push(&st, 7);
    Push(&st, 8);
    Push(&st, 9);
    Push(&st, 10);
    Push(&st, 11);
    Display(st);
    printf("\n");
    printf("%d\n", Pop(&st));
    printf("%d\n", Pop(&st));
    printf("%d\n", Pop(&st));
    printf("%d\n", Peek(st, 3));
    printf("%d\n", isEmpty(st));
    printf("%d\n", isFull(st));
    printf("%d\n", stackTop(st));
    return 0;

}