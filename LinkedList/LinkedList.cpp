#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;


void create(int A[], int n)
{
    struct Node *t, *last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data= A[0];
    first->next = NULL;
    last = first;
    for(int i= 1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next= NULL;
        last->next = t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while (p!=NULL)
    {
        printf("%d ", p->data);
        p= p->next;
    }
}

void RDisplay(struct Node *p)
{
    if (p!= NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

int count(struct Node *p)
{
    if (p!= 0)
    {
            return 1+count(p->next);
    } else {
        return 0;
    }

}

int Add(struct Node *p)
{
    if (p)
    {
        return p->data + Add(p->next);
    } else {
        return 0;
    }
}

void Insert(int pos, int x)
{
    Node *t, *p;
    if (pos == 0)
    {
        t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else
    {
        p = first;
        for (int i=0; i<pos-1 && p;i++)
        {
            p=p->next;
        }
        if (p)
        {
            t= new Node;
            t->data = x;
            t->next = p->next;
            p->next= t;
        }
    }
}

int LinearSearch(Node *p, int key)
{
    static struct Node *q= NULL;
    if (p)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return 1;
        }
        else {
            q= p;
            return LinearSearch(p->next, key);
        }
    }
    return 0;
}

int max(struct Node *p)
{
    if (p)
    {
        if (p->data > max(p->next))
        {
            return p->data;
        } else {
            return max(p->next);
        }
    } else {
        return 0;
    }
}

void Delete(int pos)
{
    Node *p, *q;
    p = first;
    if (pos == 0)
    {
        q= first;
        first = first->next;
        free(q);
    }
    else
    {
        for (int i=0; i<pos-1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {   q = p->next;
            p->next = p->next->next;
            free(q);
        }
    }
}
int CheckSorted(struct Node *p)
{
    int x= INT_MIN;
    while(p)
    {
        if(p->data < x ) return 0;
        x= p->data;
        p= p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q= p->next;
    while(q!=NULL)
    {
        if (p->data!=q->data)
        {
            p=q;
            q= q->next;
        }
        else
        {
            p->next= q->next;
            free(q);
            q=p->next;
        }
    }
}

void Reverse1(struct Node *p)
{
    struct Node *q=NULL, *r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Reverse2(struct Node *q, struct Node *p)
{
    if(p)
    {
        Reverse2(p,p->next);
        p->next=q;
    }
        else
            first=q;
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p= q= f;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    if (p==q)
        return 1;
    else
        return 0;
}
int main()
{
    int A[]= {3,3,5,5,7,10,10,10,15};
    create(A,5);
    RDisplay(first);
    printf("\n");
    printf("%d", count(first));
    printf("\n");
    if (CheckSorted(first))
    {
        printf("Sorted");
    } else {
        printf("Not Sorted");
    }
    printf("\n");
    printf("%d", Add(first));
    printf("\n");
    printf("%d", max(first));
    printf("\n");
    printf("%d", LinearSearch(first, 10));
    printf("\n");
    printf("%d", LinearSearch(first, 30));
    printf("\n");
    Display(first);
    printf("\n");
    Insert(3,20);
    Display(first);
    printf("\n");
    Delete(0);
    Display(first);
    printf("\n");
    RemoveDuplicate(first);
    Display(first);
    printf("\n");
    Reverse2(NULL, first);
    Display(first);
    printf("\n");


    free(first);
    int B[]= {3,8,9,6,5};
    create(B,5);

    struct Node *t1, *t2;
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    if (isLoop(first))
    {
        printf("Loop");
    } else {
        printf("Not Loop");
    }

    return 0;
}