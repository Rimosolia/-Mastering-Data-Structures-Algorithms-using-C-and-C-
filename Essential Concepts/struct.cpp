#include <stdio.h>
#include<iostream>

using namespace std;


struct Rectangle
{
    int length;
    int breadth;
} r1; //Declare r1 local variable

//Declare r2 local variable
struct Rectangle r2; 

int main()
{   
    struct Rectangle r = {10,5};
    printf("%d\n", sizeof(r)); //Size of Struct
    
    cout<<r.length<<endl; //Read length value
    cout<<r.breadth<<endl;
    return 0;
}