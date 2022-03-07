#include <iostream>

using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        Queue(int size);
        ~Queue();
        bool isFull();
        bool isEmpty();
        void enqueue(int data);
        int dequeue();
        void display();
};


Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1 ;
    Q = new int [size];
}

Queue::~Queue()
{
    delete [] Q;
}

bool Queue::isEmpty()
{
    if (front==rear)
    {
        return true;
    } else return false;
}

bool Queue::isFull()
{
    if ((rear + 1) % size == front)
    {
        return true;
    } else return false;
}
void Queue::enqueue(int x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int Queue::dequeue() {
    int x=-1;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
        return -1;
    } else {
        front = (front + 1) % size;
        return Q[front];
    }
}


void Queue::display() {
    int i = front + 1;
    do {
        cout << Q[i] << flush;
        if (i < rear) {
            cout << " <- " << flush;
        }
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
}




int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q(sizeof(A)/sizeof(A[0]));
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
 
    // Display
    q.display();
 
    // Overflow
    q.enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }
 
    // Underflow
    q.dequeue();
    
    return 0;
}