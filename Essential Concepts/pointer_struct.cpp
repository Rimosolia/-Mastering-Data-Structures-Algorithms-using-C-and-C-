#include <stdio.h>
#include<iostream>

using namespace std;


struct Rectangle
{
    int length;
    int breadth;
};


int main()
{   
    struct Rectangle r = {10,5};
    Rectangle *p =&r;
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;


    Rectangle *p1;
    p1=(struct Rectangle *)malloc(sizeof(struct Rectangle)); // In C++, p1 = new Rectangle;
    p1->length = 15;
    p1->breadth= 7;
    cout<<p1->length<<endl;
    cout<<p1->breadth<<endl;
    return 0;
}