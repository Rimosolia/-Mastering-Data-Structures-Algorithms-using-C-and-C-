#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
}*head=NULL;

void create(int A[], int n)
{
    Node *temp, *current;
    head = (struct Node*)malloc(sizeof(Node));
    head->data = A[0];
    head->next = NULL;
    head->prev = NULL;
    current = head;
    for (int i = 1 ; i< n; i++)
    {
        temp = (struct Node*)malloc(sizeof(Node));
        temp->data = A[i];
        temp->next = NULL;
        temp->prev = current;
        current->next = temp;
        current = temp;       
    }      
}

void Display(Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int length(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current->next != NULL)
    {
        count++;
        current = current->next;
    }
    return count;

}

void Insert(int data, int pos)
{
    Node *temp, *current;
    if (pos < 0 || pos > length(head))
    {
        printf("Invalid position\n");
        return;
    }
    else if(pos == 0)
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }
    else
    {
        current = head;
        for (int i =1 ; i< pos-1;i++)
        {
            current = current->next;
        }
        temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        temp->next = current->next;
        temp->prev = current;
        current->next->prev = temp;
        current->next = temp;

    }

}


void Delete(struct Node *p, int index)
{
    int x= - 1, i;
    if (index< 1 || index > length(head))
    {
        printf("Invalid position\n");
        return;
    }

    if (index == 1)
    {
        head = head -> next;
        if (head) head -> prev = NULL;
        free(p);
        return;
    }
    else
    {
        for (i = 0; i< index-1; i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if (p->next) p->next->prev=p->prev;  
        free(p);
    }

}


void Reverse(struct Node *p)
{
    struct Node *temp;
    while(p!=NULL)
    {
        temp = p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if (p!= NULL &&p->next==NULL)
            head = p;

    }
}


void CircularLL(struct Node *p)
{
    struct Node *current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = head;
    head->prev = current;
}

int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9};
    create(A,9);
    Display(head);
    printf("\n");
    Insert(10,3);
    Display(head);
    printf("\n");
    Delete(head,2);
    Display(head);
    printf("\n");
    Reverse(head);
    Display(head);


    return 0;

}