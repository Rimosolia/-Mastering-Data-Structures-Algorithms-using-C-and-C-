#include <iostream>

using namespace std;


class Node
{
        public:
                int data;
                Node *next;
};

class Queue{
        private:
                Node *front;
                Node *rear;
        public:
                Queue();
                void enqueue(int x);
                int dequeue();
                bool isEmpty();
                void display();
                ~Queue();
};

Queue::Queue()
{
        front = nullptr;
        rear = nullptr;
}


bool Queue::isEmpty()
{
        if(front == nullptr)
                return true;
        else
                return false;
}

Queue::~Queue()
{
        Node *temp = front;
        while (front)
        {
                front = front->next;
                delete temp;
                temp = front;
        }
}

void Queue::enqueue(int x)
{
        Node *temp = new Node;
        if(temp == nullptr)
        {
                cout<<"Memory not allocated"<<endl;
                return;
        }
        else 
        {
                temp->data =x;
                temp->next = nullptr;
                if (front == nullptr)
                {
                        front = temp;
                        rear = temp;
                }
                else
                {
                        rear->next=temp;
                        rear = temp;
                }
        }
}
int Queue::dequeue()
{
        int x= -1;
        Node *p;
        if (isEmpty())
        {
                cout<<"Queue is empty"<<endl;
                return x;
        }
        else
        {
                p = front;
                x = p->data;
                front = front->next;
                delete p;
                return x;
        }
}

void Queue::display()
{
        Node *p;
        if (isEmpty())
        {
                cout<<"Queue is empty"<<endl;
                return;
        }
        else
        {
                p = front;
                while (p)
                {
                        cout<<p->data<<" <- ";
                        p = p->next;
                }
                cout<<endl;
        }
}

int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
 
    q.display();
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }
    q.dequeue();
 
    return 0;
}