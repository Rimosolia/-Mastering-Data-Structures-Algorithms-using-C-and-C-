#include <stdio.h>
#include<iostream>

using namespace std;

class Rectangle
{
private:
    int length;
    int breath;
public:

    Rectangle()
    {
        length = 0;
        breath = 0;
    }
    Rectangle(int l, int b)
    {
        length = l;
        breath = b;
    }
int area()
{
    return length*breath;
}
int perimter()
{
    int p;
    p = 2*(length+breath);
    return p;
}
void setLength(int l)
{
    length = l;
}
void setBreath(int b)
{
    breath = b;
}
int getLength()
{
    return length;

}
int getBreath()
{
    return breath;
}
~Rectangle()
{
    cout<<"Destructor";
}

};
int main()
{
    Rectangle r(60,70);
    cout<<r.area()<<endl;
    cout<<r.perimter()<<endl;
}