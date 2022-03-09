#include <iostream>
#include <stdio.h>

using namespace std;

class Node
{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};


class Queue
{
    private:
        int front;
        int rear;
        int size;
        Node **Q;
    public:
        Queue(){front=rear=-1; size = 10; Q= new Node*[size];}
        Queue(int size){front=rear=-1; this->size = size; Q= new Node*[size];}
        void Enqueue(Node *x);
        Node* Dequeue();
        int isEmpty(){return front==rear;}

};

void Queue::Enqueue(Node *x)
{
    if (rear == size -1)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    else
    {
        rear ++ ;
        Q[rear]= x;
    }
}

Node *Queue::Dequeue()
{
    Node *x = NULL;
    if (front == rear)
    {
        cout<<"Queue is empty"<<endl;
        return x;
    }
    else
    {
        front ++;
        x = Q[front];
        return x;
    }
}

class Tree
{
    private:
        Node* root;
    public:
        Tree() { root = nullptr; }
        ~Tree();
        void CreateTree();
        void Preorder(){ Preorder(root); }  // Passing Private Parameter in Constructor
        void Preorder(Node* p);
        void Postorder(){ Postorder(root); }  // Passing Private Parameter in Constructor
        void Postorder(Node* p);
        void Inorder(){ Inorder(root); }
        void Inorder(Node* p);
        void Levelorder(){ Levelorder(root); }  // Passing Private Parameter in Constructor
        void Levelorder(Node* p);
        int Height(){ return Height(root); }  // Passing Private Parameter in Constructor
        int Height(Node* p);
        Node* getRoot(){ return root; }
};


void Tree::CreateTree()
{
    Node *p;
    Node *t;
    int x;
    Queue q(25);
    root = new Node;
    cout<<"Enter root value: "<<endl;
    cin>> x;
    root -> data = x;
    root -> lchild = root->rchild = nullptr;
    q.Enqueue(root);
    while (!q.isEmpty())
    {
        p=q.Dequeue();
        cout<<"Enter left child of "<<p->data<<" : "<<endl;
        cin>>x;
        if (x != -1)
        {
            t= new Node;
            t->data = x;
            t->lchild = t->rchild= nullptr;
            p->lchild=t;
            q.Enqueue(t);
        }
        cout<<"Enter right child of "<<p->data<<" : "<<endl;
        cin>>x;
        if (x != -1)
        {
            t= new Node;
            t->data = x;
            t->lchild = t->rchild= nullptr;
            p->rchild=t;
            q.Enqueue(t);
        }
    } 
}

void Tree::Preorder(Node* p)
{
    if (p != nullptr)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}


void Tree::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::Levelorder(Node *p)
{
    Queue q(100);
    cout<<root->data<<" , "<< endl;
    q.Enqueue(root);
    while (!q.isEmpty())
    {
        p = q.Dequeue();
        if(p->lchild)
        {
            cout<<p->lchild->data<<" , "<<endl;
            q.Enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout<<p->rchild->data<<" , "<<endl;
            q.Enqueue(p->rchild);
        }

    }
}

int Tree::Height(Node *p)
{
    int l= 0;
    int r= 0;
    if (p== nullptr)
    {
        return 0;
    }

    l = Height(p->lchild);
    r = Height(p->rchild);
    if (l> r)
        {
            return l + 1;
        }
    else
        {
            return r + 1;
        }
}

Tree::~Tree()
{
    //TODO
}

 
int main(){
 
    Tree t;
 
    t.CreateTree();
 
    cout << "Preorder: " << flush;
    t.Preorder(t.getRoot());
    cout << endl;
 
    cout << "Inorder: " << flush;
    t.Inorder(t.getRoot());
    cout << endl;
 
    cout << "Postorder: " << flush;
    t.Postorder(t.getRoot());
    cout << endl;
 
    cout << "Levelorder: " << flush;
    t.Levelorder(t.getRoot());
    cout << endl;
 
    cout << "Height: " << t.Height(t.getRoot()) << endl;
 
    cout << "Recursive Passing Private Parameter in Constructor" << endl;
 
    cout << "Preorder: " << flush;
    t.Preorder();
    cout << endl;
 
    cout << "Inorder: " << flush;
    t.Inorder();
    cout << endl;
 
    cout << "Postorder: " << flush;
    t.Postorder();
    cout << endl;
 
    cout << "Levelorder: " << flush;
    t.Levelorder();
    cout << endl;
 
    cout << "Height: " << t.Height() << endl;
 
}