#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

class CircularLinkedList{
    private:
        Node* head;
    public:
        CircularLinkedList(int A[], int n);
        ~CircularLinkedList();
        Node* getHead(){return head;}
        int Length();
        void Display();
        void recursiveDisplay(Node *p);
        void Insert(int index, int x);
        int Delete(struct Node *p, int index);

};

int CircularLinkedList::Length(){
    Node *p = head;
    int count = 0;
    while(p->next != head){
        count++;
        p = p->next;
    }
    return count;
}


void CircularLinkedList::Insert(int index, int x)
{
    Node *t;
    Node *p = head;
    t= new Node;
    t->data= x;
    t->next=NULL;
    if (index == 0)
    {
        while (p->next != head)
            p= p->next;
        p->next = t;
        t->next = head;        
        head= t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p= p->next;
        t->next= p->next;
        p->next= t;
    }
}

CircularLinkedList::CircularLinkedList(int *A, int n)
{
    Node* t;
    Node* tail;

    head = new Node;
    head->data = A[0];
    head->next = head;
    tail = head;
    for(int i = 1 ; i<n ; i++)
    {
        t= new Node;
        t->data= A[i];
        t->next = tail->next;
        tail->next= t;
        tail = t;
    }
}


void CircularLinkedList::Display(){
    Node* p = head;
    do
    {
        cout<< p->data<<" -> " <<flush;
        p= p-> next;
    } while (p!= head);
    cout<<endl;
    
}


 
void CircularLinkedList::recursiveDisplay(Node *p)
{
    static int flag = 0;
    if (p!= head|| flag==0)
    {
        flag = 1;
        cout<<p->data<< "->" << flush;
        recursiveDisplay(p->next);
    }
    flag - 0;
}

CircularLinkedList::~CircularLinkedList()
{
    Node* p = head;
    while(p->next != head)
    {
        p= p->next;
    }
    while (p!= head)
    {
        p->next= head->next;
        delete head;
        head = p->next;
    }

    if (p==head)
    {
        delete head;
        head = nullptr;
    }
}

int CircularLinkedList::Delete(struct Node *p, int index)
{
    Node *t;
    if (index <0 || index > Length()) return -1;
    if (index == 0)
    {
        t= head;
        while (t->next != head)
            t= t->next;
        t->next = head->next;
        delete head;
        head = t->next;
        return 1;
    }
    else 
    {
        p = head;
        for (int i = 0; i < index - 1; i++)
            p= p->next;
        t= p-> next;
        p->next = p->next->next;
        delete t;
        return 1;
    }
}

int main()
{
    int A[] = {1,3,5,7,9};
    CircularLinkedList cl(A, sizeof(A)/sizeof(A[0]));
    cl.Display();
    Node *h = cl.getHead();
    cl.recursiveDisplay(h);
    cl.Insert(0,30);
    cout<<endl;
    cl.Display();
    cl.Delete(h,1);
    cout<<endl;
    cl.Display();

    return 0;
}