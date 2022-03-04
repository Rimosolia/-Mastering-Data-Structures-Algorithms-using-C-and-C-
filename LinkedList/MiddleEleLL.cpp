#include<iostream>
#include<stack>
#include<cmath>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

Node* head = new Node;
void create(int A[], int n){
    Node* temp;
    Node* tail;
 
    head->data = A[0];
    head->next = nullptr;
    tail = head;
 
    for (int i=1; i<n; i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
}

void middleNode1(Node* p){
    int length = 0;
    while (p){
        length++;
        p = p->next;
    }
 
    int index = (int)ceil(length/2.0); // ceil() returns the smallest integer greater than or equal to the argument
    Node* q = head;
    for (int i=0; i<index-1; i++){
        q = q->next;
    }
    cout << "Middle Element (Method-I): " << q->data << endl;
}

void middleNode2(Node *p)
{
    stack<Node*> s;
    while(p)
    {
        s.push(p);
        p = p->next;
    }
    int size = s.size();
    int popLength= (int)(floor(size/2.0)); // floor() returns the largest integer less than or equal to the argument
    while(popLength)
    {
        s.pop();
        popLength--;
    }
    cout << "Middle Element (Method-II): " << s.top()->data << endl;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    create(A, sizeof(A)/sizeof(A[0]));
    middleNode1(head);
    middleNode2(head);
    return 0;
}