#include <stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int a= 10;
    int &r = a; //reference
    int b= 25;
    r = b;
    cout<<a<<endl;
}