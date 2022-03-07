#include <iostream>
#include<cstring>
#include <stack>
#include<string>

using namespace std;
 
class Node{
public:
    int data;
    Node* next;
};
 
class Stack{
private:
    Node* top;
public:
    Stack();
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int isFull();
    int stackTop();
};
 
Stack::Stack() {
    top = nullptr;
}
 
Stack::~Stack() {
    Node* p = top;
    while (top){
        top = top->next;
        delete p;
        p = top;
    }
}
 
void Stack::push(int x) {
    Node* t = new Node;
    if (t == nullptr){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}
 
int Stack::pop() {
    Node* p;
    int x = -1;
    if (top == nullptr){
        cout << "Stack Underflow!" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}
 
int Stack::isFull() {
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}
 
int Stack::isEmpty() {
    return top ? 0 : 1;
}
 
int Stack::stackTop() {
    if (top){
        return top->data;
    }
    return -1;
}
 
int Stack::peek(int index) {
    if (isEmpty()){
        return -1;
    } else {
        Node* p = top;
 
        for (int i=0; p != nullptr && i<index-1; i++){
            p = p->next;
        }
 
        if (p != nullptr){
            return p->data;
        } else {
            return -1;
        }
    }
}
 
 
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/'){
        return 0;
    }
    return 1;
}
 
int operation(char op, int x, int y){
    if (op == '+'){
        return x + y;
    } else if (op == '-'){
        return x - y;
    } else if (op == '*'){
        return x * y;
    } else if (op == '/'){
        return x / y;
    }
}


int OutPre(char s)
{
    if (s == '+' || s == '-')
    {
        return 1;
    }
    else
    if (s=='*' || s=='/')
    {
        return 3;
    }
    if (s=='^') return 6;
    else
    if (s=='(') return 7;
    else return 0;

}

int InPre(char s)
{
    if (s == '+' || s == '-')
    {
        return 2;
    }
    else
    if (s=='*' || s=='/')
    {
        return 4;
    }
    if (s=='^') return 5;
    else
    if (s=='(') return 0;
    else return 0;
}

char *IntoPost(char *infix)
{
    char *postfix = new char[strlen(infix)+2];
    int i, j = 0;
    stack<char> s;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        postfix[j++] = infix[i++];
        else
        if (s.empty() || OutPre(infix[i]) > InPre(s.top()))
        {
            s.push(infix[i++]);
        }
        else
        if (OutPre(infix[i]) == InPre(s.top()))
        s.pop();
        else
        {
            postfix[j++] = s.top();
            s.pop();
        }
    }
    while (!s.empty() && s.top() != ')')
    {
        postfix[j++] = s.top();
        s.pop();
    }
    postfix[j] = '\0';
    return postfix;
}
 
int postfixEvaluate(char* postfix){
    stack<int> stk;
    int x;
    int y;
    int result;
    for (int i=0; postfix[i]!='\0'; i++){
        if (isOperand(postfix[i])){
            // int typecast would not work because of char so subtract '0'
            stk.push(postfix[i]-'0');
        } else {
            y = stk.top();
            stk.pop();
            x = stk.top();
            stk.pop();
            result = operation(postfix[i], x, y);
            stk.push(result);
        }
    }
    result = stk.top();
    stk.pop();
    return result;
}
 
int Evaluate(char* postfix){
    Stack stk;
    int x;
    int y;
    int result;
    for (int i=0; postfix[i]!='\0'; i++){
        if (isOperand(postfix[i])){
            // int typecast would not work because of char so subtract '0'
            stk.push(postfix[i]-'0');
        } else {
            y = stk.pop();
            x = stk.pop();
            result = operation(postfix[i], x, y);
            stk.push(result);
        }
    }
    result = stk.pop();
    return result;
}
 
int main() {
    char infix[] = "2*3+1+5+4/2";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " <<  IntoPost(infix) << endl;
    cout << "Evaluation: " << Evaluate(IntoPost(infix)) << endl;
    char postfix[] = "35*62/+4-";
    cout << Evaluate(postfix) << endl;
    cout << postfixEvaluate(postfix) << endl;
 
    return 0;
}