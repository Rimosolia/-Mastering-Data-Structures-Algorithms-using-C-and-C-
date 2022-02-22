#include<iostream>
#include<stdio.h>
using namespace std;

int Factorial(int n)
{
    if (n==0)
        return 1;
    return Factorial(n-1)*n;
}

int main()
{
    int r;
    cin>>r;
    cout<<"Result: " << Factorial(r) << endl;
    
}